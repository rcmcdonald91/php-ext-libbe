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

#include "php_libbe.h"

#include <sys/param.h>
#include <be.h>

typedef struct {
	libbe_handle_t	*be;
	zend_object	std;
} php_libbe;

static inline php_libbe *libbe_from_obj(zend_object *obj) {
	return (php_libbe *)((char *)(obj) - XtOffsetOf(php_libbe, std));
}

#define Z_LIBBE_P(zv) libbe_from_obj(Z_OBJ_P(zv))
