/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 741bef88b0f09e4c8277286815ced3cd0eac9273 */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_TYPE_MASK_EX(arginfo_libbe_init, 0, 0, LibbeHandle, MAY_BE_FALSE)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, root, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_libbe_close, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, handle, LibbeHandle, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_be_active_name, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, handle, LibbeHandle, 0)
ZEND_END_ARG_INFO()

#define arginfo_be_active_path arginfo_be_active_name

#define arginfo_be_nextboot_name arginfo_be_active_name

#define arginfo_be_nextboot_path arginfo_be_active_name

#define arginfo_be_root_path arginfo_be_active_name

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_be_snapshot, 0, 4, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, handle, LibbeHandle, 0)
	ZEND_ARG_TYPE_INFO(0, be_name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, snap_name, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, recursive, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(1, result, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_be_is_auto_snapshot_name, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, handle, LibbeHandle, 0)
	ZEND_ARG_TYPE_INFO(0, snap_name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_be_create, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, handle, LibbeHandle, 0)
	ZEND_ARG_TYPE_INFO(0, be_name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_be_create_depth, 0, 4, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, handle, LibbeHandle, 0)
	ZEND_ARG_TYPE_INFO(0, be_name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, snap_name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, depth, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_be_create_from_existing, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, handle, LibbeHandle, 0)
	ZEND_ARG_TYPE_INFO(0, be_name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, be_origin, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_be_create_from_existing_snap, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, handle, LibbeHandle, 0)
	ZEND_ARG_TYPE_INFO(0, be_name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, snap_name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_be_rename, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, handle, LibbeHandle, 0)
	ZEND_ARG_TYPE_INFO(0, be_name_old, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, be_name_new, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_be_activate, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, handle, LibbeHandle, 0)
	ZEND_ARG_TYPE_INFO(0, be_name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, temporary, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_be_deactivate arginfo_be_activate

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_be_destroy, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, handle, LibbeHandle, 0)
	ZEND_ARG_TYPE_INFO(0, be_name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, options, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_be_nicenum, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, num, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_be_mount, 0, 4, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, handle, LibbeHandle, 0)
	ZEND_ARG_TYPE_INFO(0, be_name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, mount_point, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(1, result, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_be_mounted_at, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, handle, LibbeHandle, 0)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(1, details, IS_ARRAY, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_be_unmount, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, handle, LibbeHandle, 0)
	ZEND_ARG_TYPE_INFO(0, be_name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_libbe_errno, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, handle, LibbeHandle, 0)
ZEND_END_ARG_INFO()

#define arginfo_libbe_error_description arginfo_be_active_name

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_libbe_print_on_error, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, handle, LibbeHandle, 0)
	ZEND_ARG_TYPE_INFO(0, doprint, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_be_root_concat, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, handle, LibbeHandle, 0)
	ZEND_ARG_TYPE_INFO(0, be_name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(1, result, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_be_validate_name arginfo_be_create

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_be_validate_snap, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, handle, LibbeHandle, 0)
	ZEND_ARG_TYPE_INFO(0, snap_name, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_be_exists arginfo_be_create

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_be_export, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, handle, LibbeHandle, 0)
	ZEND_ARG_TYPE_INFO(0, be_name, IS_STRING, 0)
	ZEND_ARG_INFO(0, stream)
ZEND_END_ARG_INFO()

#define arginfo_be_import arginfo_be_export

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_be_get_bootenv_props, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, handle, LibbeHandle, 0)
	ZEND_ARG_TYPE_INFO(1, be_list, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_be_get_dataset_props, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, handle, LibbeHandle, 0)
	ZEND_ARG_TYPE_INFO(0, ds_name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(1, props, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_be_get_dataset_snapshots, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, handle, LibbeHandle, 0)
	ZEND_ARG_TYPE_INFO(0, ds_name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(1, snap_list, IS_ARRAY, 0)
ZEND_END_ARG_INFO()


ZEND_FUNCTION(libbe_init);
ZEND_FUNCTION(libbe_close);
ZEND_FUNCTION(be_active_name);
ZEND_FUNCTION(be_active_path);
ZEND_FUNCTION(be_nextboot_name);
ZEND_FUNCTION(be_nextboot_path);
ZEND_FUNCTION(be_root_path);
ZEND_FUNCTION(be_snapshot);
ZEND_FUNCTION(be_is_auto_snapshot_name);
ZEND_FUNCTION(be_create);
ZEND_FUNCTION(be_create_depth);
ZEND_FUNCTION(be_create_from_existing);
ZEND_FUNCTION(be_create_from_existing_snap);
ZEND_FUNCTION(be_rename);
ZEND_FUNCTION(be_activate);
ZEND_FUNCTION(be_deactivate);
ZEND_FUNCTION(be_destroy);
ZEND_FUNCTION(be_nicenum);
ZEND_FUNCTION(be_mount);
ZEND_FUNCTION(be_mounted_at);
ZEND_FUNCTION(be_unmount);
ZEND_FUNCTION(libbe_errno);
ZEND_FUNCTION(libbe_error_description);
ZEND_FUNCTION(libbe_print_on_error);
ZEND_FUNCTION(be_root_concat);
ZEND_FUNCTION(be_validate_name);
ZEND_FUNCTION(be_validate_snap);
ZEND_FUNCTION(be_exists);
ZEND_FUNCTION(be_export);
ZEND_FUNCTION(be_import);
ZEND_FUNCTION(be_get_bootenv_props);
ZEND_FUNCTION(be_get_dataset_props);
ZEND_FUNCTION(be_get_dataset_snapshots);


static const zend_function_entry ext_functions[] = {
	ZEND_FE(libbe_init, arginfo_libbe_init)
	ZEND_FE(libbe_close, arginfo_libbe_close)
	ZEND_FE(be_active_name, arginfo_be_active_name)
	ZEND_FE(be_active_path, arginfo_be_active_path)
	ZEND_FE(be_nextboot_name, arginfo_be_nextboot_name)
	ZEND_FE(be_nextboot_path, arginfo_be_nextboot_path)
	ZEND_FE(be_root_path, arginfo_be_root_path)
	ZEND_FE(be_snapshot, arginfo_be_snapshot)
	ZEND_FE(be_is_auto_snapshot_name, arginfo_be_is_auto_snapshot_name)
	ZEND_FE(be_create, arginfo_be_create)
	ZEND_FE(be_create_depth, arginfo_be_create_depth)
	ZEND_FE(be_create_from_existing, arginfo_be_create_from_existing)
	ZEND_FE(be_create_from_existing_snap, arginfo_be_create_from_existing_snap)
	ZEND_FE(be_rename, arginfo_be_rename)
	ZEND_FE(be_activate, arginfo_be_activate)
	ZEND_FE(be_deactivate, arginfo_be_deactivate)
	ZEND_FE(be_destroy, arginfo_be_destroy)
	ZEND_FE(be_nicenum, arginfo_be_nicenum)
	ZEND_FE(be_mount, arginfo_be_mount)
	ZEND_FE(be_mounted_at, arginfo_be_mounted_at)
	ZEND_FE(be_unmount, arginfo_be_unmount)
	ZEND_FE(libbe_errno, arginfo_libbe_errno)
	ZEND_FE(libbe_error_description, arginfo_libbe_error_description)
	ZEND_FE(libbe_print_on_error, arginfo_libbe_print_on_error)
	ZEND_FE(be_root_concat, arginfo_be_root_concat)
	ZEND_FE(be_validate_name, arginfo_be_validate_name)
	ZEND_FE(be_validate_snap, arginfo_be_validate_snap)
	ZEND_FE(be_exists, arginfo_be_exists)
	ZEND_FE(be_export, arginfo_be_export)
	ZEND_FE(be_import, arginfo_be_import)
	ZEND_FE(be_get_bootenv_props, arginfo_be_get_bootenv_props)
	ZEND_FE(be_get_dataset_props, arginfo_be_get_dataset_props)
	ZEND_FE(be_get_dataset_snapshots, arginfo_be_get_dataset_snapshots)
	ZEND_FE_END
};


static const zend_function_entry class_LibbeHandle_methods[] = {
	ZEND_FE_END
};

static void register_libbe_symbols(int module_number)
{
	REGISTER_LONG_CONSTANT("BE_ERR_SUCCESS", BE_ERR_SUCCESS, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("BE_ERR_INVALIDNAME", BE_ERR_INVALIDNAME, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("BE_ERR_EXISTS", BE_ERR_EXISTS, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("BE_ERR_NOENT", BE_ERR_NOENT, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("BE_ERR_PERMS", BE_ERR_PERMS, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("BE_ERR_DESTROYACT", BE_ERR_DESTROYACT, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("BE_ERR_DESTROYMNT", BE_ERR_DESTROYMNT, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("BE_ERR_BADPATH", BE_ERR_BADPATH, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("BE_ERR_PATHBUSY", BE_ERR_PATHBUSY, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("BE_ERR_PATHLEN", BE_ERR_PATHLEN, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("BE_ERR_BADMOUNT", BE_ERR_BADMOUNT, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("BE_ERR_NOORIGIN", BE_ERR_NOORIGIN, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("BE_ERR_MOUNTED", BE_ERR_MOUNTED, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("BE_ERR_NOMOUNT", BE_ERR_NOMOUNT, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("BE_ERR_ZFSOPEN", BE_ERR_ZFSOPEN, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("BE_ERR_ZFSCLONE", BE_ERR_ZFSCLONE, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("BE_ERR_IO", BE_ERR_IO, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("BE_ERR_NOPOOL", BE_ERR_NOPOOL, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("BE_ERR_NOMEM", BE_ERR_NOMEM, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("BE_ERR_UNKNOWN", BE_ERR_UNKNOWN, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("BE_ERR_INVORIGIN", BE_ERR_INVORIGIN, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("BE_ERR_HASCLONES", BE_ERR_HASCLONES, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("BE_DESTROY_FORCE", BE_DESTROY_FORCE, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("BE_DESTROY_ORIGIN", BE_DESTROY_ORIGIN, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("BE_DESTROY_AUTOORIGIN", BE_DESTROY_AUTOORIGIN, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("BE_MNT_FORCE", BE_MNT_FORCE, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("BE_MNT_DEEP", BE_MNT_DEEP, CONST_PERSISTENT);
}

static zend_class_entry *register_class_LibbeHandle(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "LibbeHandle", class_LibbeHandle_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_NO_DYNAMIC_PROPERTIES|ZEND_ACC_NOT_SERIALIZABLE;

	return class_entry;
}
