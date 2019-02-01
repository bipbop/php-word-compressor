PHP_ARG_ENABLE(wordcompression, whether to enable wordcompression support,
[  --enable-wordcompression          Enable wordcompression support])

if test "$PHP_WORDCOMPRESSION" != "no"; then
  PHP_ADD_LIBRARY(wordcompression, "", EXTRA_LDFLAGS)
  AC_DEFINE(HAVE_WORDCOMPRESSION, 1, [ Have wordcompression support ])
  PHP_NEW_EXTENSION(wordcompression, wordcompression.c, $ext_shared)
fi

-lwordcompression