/*
   +----------------------------------------------------------------------+
   | Copyright (c) The PHP Group                                          |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | https://www.php.net/license/3_01.txt                                 |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Author: R. Christian McDonald <cmcdonald@netgate.com                 |
   +----------------------------------------------------------------------+
*/

#ifndef PHP_LIBBE_H
# define PHP_LIBBE_H

extern zend_module_entry libbe_module_entry;
# define phpext_libbe_ptr &libbe_module_entry

/* remember to update verison string here too */
# define PHP_LIBBE_VERSION "0.1.4"

/* internal resource management */
#define le_libbe_name "LibbeHandle"

/* for easily registering libbe constants */
#define REGISTER_LIBBE_CONSTANT(__c) REGISTER_LONG_CONSTANT(#__c, __c, CONST_CS | CONST_PERSISTENT)

PHP_MINIT_FUNCTION(libbe);
PHP_RINIT_FUNCTION(libbe);
PHP_MINFO_FUNCTION(libbe);

PHP_FUNCTION(libbe_init);
PHP_FUNCTION(libbe_close);
PHP_FUNCTION(libbe_refresh);
PHP_FUNCTION(libbe_check);
PHP_FUNCTION(libbe_version);
PHP_FUNCTION(be_active_name);
PHP_FUNCTION(be_active_path);
PHP_FUNCTION(be_nextboot_name);
PHP_FUNCTION(be_nextboot_path);
PHP_FUNCTION(be_root_path);
PHP_FUNCTION(be_snapshot);
PHP_FUNCTION(be_is_auto_snapshot_name);
PHP_FUNCTION(be_create);
PHP_FUNCTION(be_create_depth);
PHP_FUNCTION(be_create_from_existing);
PHP_FUNCTION(be_create_from_existing_snap);
PHP_FUNCTION(be_rename);
PHP_FUNCTION(be_activate);
#if __FreeBSD_version >= 1300000
PHP_FUNCTION(be_deactivate);
#endif
PHP_FUNCTION(be_destroy);
PHP_FUNCTION(be_nicenum);
PHP_FUNCTION(be_mount);
PHP_FUNCTION(be_unmount);
PHP_FUNCTION(libbe_errno);
PHP_FUNCTION(libbe_error_description);
PHP_FUNCTION(libbe_print_on_error);
PHP_FUNCTION(be_root_concat);
PHP_FUNCTION(be_validate_name);
PHP_FUNCTION(be_validate_snap);
PHP_FUNCTION(be_exists);
PHP_FUNCTION(be_get_bootenv_props);

# if defined(ZTS) && defined(COMPILE_DL_LIBBE)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_LIBBE_H */
