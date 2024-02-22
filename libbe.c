/*
 * libbe.c
 *
 * Copyright (c) 2022-2024 R. Christian McDonald <rcm@rcm.sh>
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "main/php_network.h"

#include "libbe_private.h"
#include "libbe_arginfo.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

static zend_class_entry *libbe_ce;
static zend_object_handlers libbe_object_handlers;

static void php_nvlist_to_zval_array(zval *dsczval, nvlist_t *srcnvl);

static php_libbe *
init_libbe_handle_into_zval(zval *dstzval)
{
	php_libbe *bh;

	object_init_ex(dstzval, libbe_ce);
	bh = Z_LIBBE_P(dstzval);

	return bh;
}

static zend_object *
libbe_create_object(zend_class_entry *class_type)
{
	php_libbe *intern = zend_object_alloc(sizeof(php_libbe), class_type);

	zend_object_std_init(&intern->std, class_type);
	object_properties_init(&intern->std, class_type);

	return &intern->std;
}

static zend_function *libbe_get_constructor(zend_object *object)
{
	php_error_docref(NULL, E_WARNING, "Cannot directly construct LibbeHandle, use libbe_init() instead");
	return NULL;
}

static void
libbe_free_obj(zend_object *object)
{
	php_libbe *bh = libbe_from_obj(object);

	if (bh->be)
		libbe_close(bh->be);

	zend_object_std_dtor(&bh->std);
}

PHP_MINIT_FUNCTION(libbe)
{
	register_libbe_symbols(module_number);

	libbe_ce = register_class_LibbeHandle();
	libbe_ce->create_object = libbe_create_object;
	libbe_ce->default_object_handlers = &libbe_object_handlers;

	memcpy(&libbe_object_handlers, &std_object_handlers, sizeof(zend_object_handlers));
	libbe_object_handlers.offset = XtOffsetOf(php_libbe, std);

	libbe_object_handlers.free_obj = libbe_free_obj;
	libbe_object_handlers.get_constructor = libbe_get_constructor;
	libbe_object_handlers.compare = zend_objects_not_comparable;

	return SUCCESS;
}

PHP_FUNCTION(libbe_init)
{
	char *root = NULL;
	size_t root_len = 0;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STRING_OR_NULL(root, root_len)
	ZEND_PARSE_PARAMETERS_END();

	libbe_handle_t *be;
	php_libbe *bh;

	if ((be = libbe_init(root)) == NULL)
		RETURN_FALSE;

	bh = init_libbe_handle_into_zval(return_value);
	bh->be = be;
}

PHP_FUNCTION(libbe_close)
{
	zval *zbe;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zbe, libbe_ce)
	ZEND_PARSE_PARAMETERS_END();
}

PHP_FUNCTION(be_active_name)
{
	zval *zbe;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zbe, libbe_ce)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_STRING(be_active_name(Z_LIBBE_P(zbe)->be));
}

PHP_FUNCTION(be_active_path)
{
	zval *zbe;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zbe, libbe_ce)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_STRING(be_active_path(Z_LIBBE_P(zbe)->be));
}

PHP_FUNCTION(be_nextboot_name)
{
	zval *zbe;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zbe, libbe_ce)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_STRING(be_nextboot_name(Z_LIBBE_P(zbe)->be));
}

PHP_FUNCTION(be_nextboot_path)
{
	zval *zbe;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zbe, libbe_ce)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_STRING(be_nextboot_path(Z_LIBBE_P(zbe)->be));
}

PHP_FUNCTION(be_root_path)
{
	zval *zbe;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zbe, libbe_ce)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_STRING(be_root_path(Z_LIBBE_P(zbe)->be));
}

PHP_FUNCTION(be_snapshot)
{
	zval *zbe, *zresult = NULL;
	char *be_name, *snap_name;
	size_t  be_name_len, snap_name_len;
	zend_bool recursive;

	ZEND_PARSE_PARAMETERS_START(4, 5)
		Z_PARAM_OBJECT_OF_CLASS(zbe, libbe_ce)
		Z_PARAM_STRING(be_name, be_name_len)
		Z_PARAM_STRING_OR_NULL(snap_name, snap_name_len)
		Z_PARAM_BOOL(recursive)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(zresult)
	ZEND_PARSE_PARAMETERS_END();

	int ret;
	char snapshot[BE_MAXPATHLEN];

	RETVAL_LONG(ret = be_snapshot(Z_LIBBE_P(zbe)->be, be_name,
	    snap_name, recursive, snapshot));

	if (zresult && (ret == BE_ERR_SUCCESS)) {
		ZVAL_DEREF(zresult);
		ZVAL_STRING(zresult, snapshot);
	}
}

PHP_FUNCTION(be_is_auto_snapshot_name)
{
	zval *zbe;
	char *snap_name;
	size_t snap_name_len;

	php_libbe	*bh;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zbe, libbe_ce)
		Z_PARAM_STRING(snap_name, snap_name_len)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_BOOL(be_is_auto_snapshot_name(Z_LIBBE_P(zbe)->be, snap_name));
}

PHP_FUNCTION(be_create)
{
	zval *zbe;
	char *be_name;
	size_t be_name_len;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zbe, libbe_ce)
		Z_PARAM_STRING(be_name, be_name_len)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG(be_create(Z_LIBBE_P(zbe)->be, be_name));
}

PHP_FUNCTION(be_create_depth)
{
	zval *zbe;
	char *be_name, *snap_name;
	size_t be_name_len, snap_name_len;
	zend_long depth;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(zbe, libbe_ce)
		Z_PARAM_STRING(be_name, be_name_len)
		Z_PARAM_STRING(snap_name, snap_name_len)
		Z_PARAM_LONG(depth)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG(be_create_depth(Z_LIBBE_P(zbe)->be, be_name,
	    snap_name, depth));
}

PHP_FUNCTION(be_create_from_existing)
{
	zval *zbe;
	char *be_name, *be_origin;
	size_t be_name_len, be_origin_len;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zbe, libbe_ce)
		Z_PARAM_STRING(be_name, be_name_len)
		Z_PARAM_STRING(be_origin, be_origin_len)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG(be_create_from_existing(Z_LIBBE_P(zbe)->be,
	    be_name, be_origin));
}

PHP_FUNCTION(be_create_from_existing_snap)
{
	zval *zbe;
	char *be_name, *snap_name;
	size_t be_name_len, snap_name_len;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zbe, libbe_ce)
		Z_PARAM_STRING(be_name, be_name_len)
		Z_PARAM_STRING(snap_name, snap_name_len)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG(be_create_from_existing_snap(Z_LIBBE_P(zbe)->be,
	    be_name, snap_name));
}

PHP_FUNCTION(be_rename)
{
	zval *zbe;
	char *be_name_old, *be_name_new;
	size_t be_name_old_len, be_name_new_len;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zbe, libbe_ce)
		Z_PARAM_STRING(be_name_old, be_name_old_len)
		Z_PARAM_STRING(be_name_new, be_name_new_len)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG(be_rename(Z_LIBBE_P(zbe)->be, be_name_old, be_name_new));
}

PHP_FUNCTION(be_activate)
{
	zval *zbe;
	char *be_name;
	size_t be_name_len;
	zend_bool temporary;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zbe, libbe_ce)
		Z_PARAM_STRING(be_name, be_name_len)
		Z_PARAM_BOOL(temporary)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG(be_activate(Z_LIBBE_P(zbe)->be, be_name, temporary));
}

PHP_FUNCTION(be_deactivate)
{
	zval *zbe;
	char *be_name;
	size_t be_name_len;
	zend_bool temporary;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zbe, libbe_ce)
		Z_PARAM_STRING(be_name, be_name_len)
		Z_PARAM_BOOL(temporary)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG(be_deactivate(Z_LIBBE_P(zbe)->be, be_name, temporary));
}

PHP_FUNCTION(be_destroy)
{
	zval *zbe;
	char *be_name;
	size_t be_name_len;
	zend_long options;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zbe, libbe_ce)
		Z_PARAM_STRING(be_name, be_name_len)
		Z_PARAM_LONG(options)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG(be_destroy(Z_LIBBE_P(zbe)->be, be_name, options));
}

PHP_FUNCTION(be_nicenum)
{
	zend_long num;
	char buf[6];

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(num)
	ZEND_PARSE_PARAMETERS_END();

	be_nicenum(num, buf, sizeof (buf));

	RETURN_STRING(buf);
}

PHP_FUNCTION(be_mount)
{
	zval *zbe, *zresult = NULL;
	char *be_name, *mnt_point = NULL;
	size_t be_name_len, mnt_point_len;
	zend_long flags;

	ZEND_PARSE_PARAMETERS_START(4, 5)
		Z_PARAM_OBJECT_OF_CLASS(zbe, libbe_ce)
		Z_PARAM_STRING(be_name, be_name_len)
		Z_PARAM_STRING_OR_NULL(mnt_point, mnt_point_len)
		Z_PARAM_LONG(flags)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(zresult);
	ZEND_PARSE_PARAMETERS_END();

	int ret;
	char result[BE_MAXPATHLEN];

	RETVAL_LONG(ret = be_mount(Z_LIBBE_P(zbe)->be, be_name, mnt_point,
	    flags, result));

	if (zresult && (ret == BE_ERR_SUCCESS)) {
		ZVAL_DEREF(zresult);
		ZVAL_STRING(zresult, result);
	}
}	

PHP_FUNCTION(be_mounted_at)
{
	zval *zbe, *zdetails = NULL;
	char *path;
	size_t path_len;

	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_OBJECT_OF_CLASS(zbe, libbe_ce)
		Z_PARAM_STRING(path, path_len)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(zdetails)
	ZEND_PARSE_PARAMETERS_END();

	int ret;
	nvlist_t *bootenv;

	if (be_prop_list_alloc(&bootenv) != BE_ERR_SUCCESS) {
		php_error_docref(NULL, E_ERROR, "Failed to allocate nvlist");
		return;
	}

	RETVAL_LONG(ret = be_mounted_at(Z_LIBBE_P(zbe)->be, path, bootenv));

	if (zdetails && (ret == BE_ERR_SUCCESS)) {
		ZVAL_DEREF(zdetails);
		php_nvlist_to_zval_array(zdetails, bootenv);
	}

	be_prop_list_free(bootenv);
}

PHP_FUNCTION(be_unmount)
{
	zval *zbe;
	char *be_name;
	size_t be_name_len;
	zend_long flags;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zbe, libbe_ce)
		Z_PARAM_STRING(be_name, be_name_len)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG(be_unmount(Z_LIBBE_P(zbe)->be, be_name, flags));
}	

PHP_FUNCTION(libbe_errno)
{
	zval *zbe;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zbe, libbe_ce)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG(libbe_errno(Z_LIBBE_P(zbe)->be));
}

PHP_FUNCTION(libbe_error_description)
{
	zval *zbe;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zbe, libbe_ce)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_STRING(libbe_error_description(Z_LIBBE_P(zbe)->be));
}

PHP_FUNCTION(libbe_print_on_error)
{
	zval *zbe;
	zend_bool doprint;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zbe, libbe_ce)
		Z_PARAM_BOOL(doprint)
	ZEND_PARSE_PARAMETERS_END();

	libbe_print_on_error(Z_LIBBE_P(zbe)->be, doprint);
}

PHP_FUNCTION(be_root_concat)
{
	zval *zbe, *zresult;
	char *be_name;
	size_t be_name_len;


	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zbe, libbe_ce)
		Z_PARAM_STRING(be_name, be_name_len)
		Z_PARAM_ZVAL(zresult);
	ZEND_PARSE_PARAMETERS_END();

	int ret;
	char result[BE_MAXPATHLEN];

	RETVAL_LONG(ret = be_root_concat(Z_LIBBE_P(zbe)->be, be_name, result));

	if (zresult && (ret == BE_ERR_SUCCESS)) {
		ZVAL_DEREF(zresult);
		ZVAL_STRING(zresult, result);
	}
}

PHP_FUNCTION(be_validate_name)
{
	zval *zbe;
	char *be_name;
	size_t be_name_len;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zbe, libbe_ce)
		Z_PARAM_STRING(be_name, be_name_len)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG(be_validate_name(Z_LIBBE_P(zbe)->be, be_name));
}

PHP_FUNCTION(be_validate_snap)
{
	zval *zbe;
	char *snap_name;
	size_t snap_name_len;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zbe, libbe_ce)
		Z_PARAM_STRING(snap_name, snap_name_len)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG(be_validate_snap(Z_LIBBE_P(zbe)->be, snap_name));
}

PHP_FUNCTION(be_exists)
{
	zval *zbe;
	char *be_name;
	size_t be_name_len;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zbe, libbe_ce)
		Z_PARAM_STRING(be_name, be_name_len)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG(be_exists(Z_LIBBE_P(zbe)->be, be_name));
}

PHP_FUNCTION(be_export)
{
	zval *zbe;
	char *be_name;
	size_t be_name_len;
	zval *zres;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zbe, libbe_ce)
		Z_PARAM_STRING(be_name, be_name_len)
		Z_PARAM_RESOURCE(zres)
	ZEND_PARSE_PARAMETERS_END();

	php_stream *stream;
	php_socket_t fd;

	php_stream_from_zval(stream, zres);

	if (php_stream_cast(stream, PHP_STREAM_AS_FD, (void **)&fd, REPORT_ERRORS) == FAILURE) {
		php_error_docref(NULL, E_WARNING, "Could not use stream of type '%s'",
		    stream->ops->label);
		return;
	}

	RETURN_LONG(be_export(Z_LIBBE_P(zbe)->be, be_name, (int)fd));
}	

PHP_FUNCTION(be_import)
{
	zval *zbe;
	char *be_name;
	size_t be_name_len;
	zval *zres;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zbe, libbe_ce)
		Z_PARAM_STRING(be_name, be_name_len)
		Z_PARAM_RESOURCE(zres)
	ZEND_PARSE_PARAMETERS_END();

	php_stream *stream;
	php_socket_t fd;

	php_stream_from_zval(stream, zres);

	if (php_stream_cast(stream, PHP_STREAM_AS_FD, (void **)&fd, REPORT_ERRORS) == FAILURE) {
		php_error_docref(NULL, E_WARNING, "Could not use stream of type '%s'",
		    stream->ops->label);
		return;
	}

	RETURN_LONG(be_import(Z_LIBBE_P(zbe)->be, be_name, (int)fd));
}	

PHP_FUNCTION(be_get_bootenv_props)
{
	zval *zbe, *zlist;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zbe, libbe_ce)
		Z_PARAM_ZVAL(zlist)
	ZEND_PARSE_PARAMETERS_END();

	nvlist_t *bootenvs;

	if (be_prop_list_alloc(&bootenvs) != BE_ERR_SUCCESS) {
		php_error_docref(NULL, E_ERROR, "Failed to allocate nvlist");
		return;
	}

	RETVAL_LONG(be_get_bootenv_props(Z_LIBBE_P(zbe)->be, bootenvs));

	ZVAL_DEREF(zlist);

	php_nvlist_to_zval_array(zlist, bootenvs);

	be_prop_list_free(bootenvs);
}

PHP_FUNCTION(be_get_dataset_props)
{
	zval *zbe, *zprops;
	char *ds_name;
	size_t ds_name_len;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zbe, libbe_ce)
		Z_PARAM_STRING(ds_name, ds_name_len)
		Z_PARAM_ZVAL(zprops)
	ZEND_PARSE_PARAMETERS_END();

	nvlist_t *proplist;

	if (be_prop_list_alloc(&proplist) != BE_ERR_SUCCESS) {
		php_error_docref(NULL, E_ERROR, "Failed to allocate nvlist");
		return;
	}

	RETVAL_LONG(be_get_dataset_props(Z_LIBBE_P(zbe)->be, ds_name, proplist));

	ZVAL_DEREF(zprops);

	php_nvlist_to_zval_array(zprops, proplist);

	be_prop_list_free(proplist);
}	

PHP_FUNCTION(be_get_dataset_snapshots)
{
	zval *zbe, *zsnaps;
	char *ds_name;
	size_t ds_name_len;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zbe, libbe_ce)
		Z_PARAM_STRING(ds_name, ds_name_len)
		Z_PARAM_ZVAL(zsnaps)
	ZEND_PARSE_PARAMETERS_END();

	nvlist_t *snaplist;

	if (be_prop_list_alloc(&snaplist) != BE_ERR_SUCCESS) {
		php_error_docref(NULL, E_ERROR, "Failed to allocate nvlist");
		return;
	}

	RETVAL_LONG(be_get_dataset_snapshots(Z_LIBBE_P(zbe)->be, ds_name, snaplist));

	ZVAL_DEREF(zsnaps);

	php_nvlist_to_zval_array(zsnaps, snaplist);

	be_prop_list_free(snaplist);
}	

PHP_RINIT_FUNCTION(libbe)
{
#if defined(ZTS) && defined(COMPILE_DL_LIBBE)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}

PHP_MINFO_FUNCTION(libbe)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "libbe support", "enabled");
	php_info_print_table_end();
}

zend_module_entry libbe_module_entry = {
	STANDARD_MODULE_HEADER,
	"libbe",						/* Extension name */
	ext_functions,
	PHP_MINIT(libbe),					/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(libbe),					/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(libbe),					/* PHP_MINFO - Module info */
	PHP_LIBBE_VERSION,					/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_LIBBE
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(libbe)
#endif

/* recursively walk an nvlist of arbitrary depth while converting it to a php zend_array zval */
static void
php_nvlist_to_zval_array(zval *dsczval, nvlist_t *srcnvl)
{
	nvpair_t *curnvp;
	boolean_t bpropval;
	const char *cpropval;
	nvlist_t *npropval;
	zval next;

	array_init(dsczval);

	for (curnvp = nvlist_next_nvpair(srcnvl, NULL);
		curnvp != NULL; curnvp = nvlist_next_nvpair(srcnvl, curnvp)) {
		switch(nvpair_type(curnvp)) {
			case DATA_TYPE_BOOLEAN_VALUE:
				if (nvpair_value_boolean_value(curnvp, &bpropval) == 0)
					add_assoc_bool(dsczval, nvpair_name(curnvp), bpropval);
				break;
			case DATA_TYPE_STRING:
				if (nvpair_value_string(curnvp, &cpropval) == 0)
					add_assoc_string(dsczval, nvpair_name(curnvp), cpropval);
				break;
			case DATA_TYPE_NVLIST:
				if (nvpair_value_nvlist(curnvp, &npropval) == 0) {
					php_nvlist_to_zval_array(&next, npropval);
					add_assoc_zval(dsczval, nvpair_name(curnvp), &next);
				}
				break;
			default:
				/* unhandled nvpair datatype, just skip it... can add more later if necessary */
				break;
		}
	}
}
