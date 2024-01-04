/*
 * php_libbe.h
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

#ifndef _PHP_LIBBE_H
#define _PHP_LIBBE_H

#include "php.h"

#if defined(__GNUC__) && __GNUC__ >= 4
# define PHP_LIBBE_API __attribute__ ((visibility("default")))
#else
# define PHP_LIBBE_API
#endif

extern zend_module_entry libbe_module_entry;
#define phpext_libbe_ptr &libbe_module_entry

#endif	/* _PHP_LIBBE_H */
