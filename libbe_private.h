/*
 * libbe_private.h
 *
 * Copyright (c) 2022-204 R. Christian McDonald <rcm@rcm.sh>
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

#ifndef _PHP_LIBBE_PRIVATE_H
#define _PHP_LIBBE_PRIVATE_H

#include "php_libbe.h"

#include "php_version.h"
#define PHP_LIBBE_VERSION PHP_VERSION

#include <sys/param.h>
#include <be.h>

typedef struct {
	libbe_handle_t	*be;
	zend_object 	std;
} php_libbe;

static inline php_libbe *libbe_from_obj(zend_object *obj) {
	return (php_libbe *)((char *)(obj) - XtOffsetOf(php_libbe, std));
}

#define Z_LIBBE_P(zv) libbe_from_obj(Z_OBJ_P(zv))

#endif /* _PHP_LIBBE_PRIVATE_H */
