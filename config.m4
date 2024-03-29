PHP_ARG_WITH([libbe],
  [for libbe support],
  [AS_HELP_STRING([--with-libbe],
    [Include libbe support])])

if test "$PHP_LIBBE" != "no"; then
  PHP_ADD_INCLUDE(/usr/src/sys/contrib/openzfs/include)
  PHP_ADD_INCLUDE(/usr/src/sys/contrib/openzfs/lib/libspl/include)

  PHP_ADD_LIBRARY_WITH_PATH(be, /lib, LIBBE_SHARED_LIBADD)
  PHP_ADD_LIBRARY_WITH_PATH(nvpair, /lib, LIBBE_SHARED_LIBADD)

  PHP_LIBBE_CFLAGS="-include /usr/src/sys/contrib/openzfs/include/os/freebsd/spl/sys/ccompile.h -DHAVE_ISSETUGID -include /usr/src/sys/modules/zfs/zfs_config.h"
  PHP_NEW_EXTENSION(libbe, libbe.c, $ext_shared,, $PHP_LIBBE_CFLAGS)

  PHP_SUBST(LIBBE_SHARED_LIBADD)
fi
