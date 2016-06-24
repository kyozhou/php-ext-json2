dnl
dnl $Id$
dnl

PHP_ARG_ENABLE(json2, whether to enable JavaScript Object Serialization support,
[  --disable-json2          Disable JavaScript Object Serialization support], yes)

if test "$PHP_JSON2" != "no"; then
  AC_DEFINE([HAVE_JSON2],1 ,[whether to enable JavaScript Object Serialization support])
  AC_HEADER_STDC

  PHP_NEW_EXTENSION(json2, json2.c utf8_decode.c JSON2_parser.c, $ext_shared)
  PHP_INSTALL_HEADERS([ext/json2], [php_json2.h])
  PHP_SUBST(JSON_SHARED_LIBADD)
fi
