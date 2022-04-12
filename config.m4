PHP_ARG_WITH([libbe],
  [for libbe support],
  [AS_HELP_STRING([--with-libbe],
    [Include libbe support])])

if test "$PHP_LIBBE" != "no"; then
  dnl libnvpair
  PHP_ADD_INCLUDE(/sys/contrib/openzfs/include)
  PHP_ADD_INCLUDE(/usr/src/sys/cddl/compat/opensolaris)
  PHP_ADD_LIBRARY_WITH_PATH(nvpair, /lib, LIBBE_SHARED_LIBADD)

  dnl libbe
  PHP_ADD_INCLUDE(/usr/include)
  PHP_ADD_LIBRARY_WITH_PATH(be, /lib, LIBBE_SHARED_LIBADD)

  PHP_NEW_EXTENSION(libbe, libbe.c, $ext_shared,, -DNEED_SOLARIS_BOOLEAN)

  PHP_SUBST(LIBBE_SHARED_LIBADD)
fi
