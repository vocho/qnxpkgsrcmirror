$NetBSD$

--- src/rxvt.h.orig	2012-01-19 17:08:56.000000000 +0000
+++ src/rxvt.h
@@ -19,6 +19,9 @@
 #ifdef HAVE_SYS_STRREDIR_H
 #include <sys/strredir.h>
 #endif
+#ifdef __QNXNTO__
+#include <wctype.h>
+#endif
 
 #if HAVE_WCHAR_H
 # include <wchar.h>
@@ -633,7 +636,11 @@ typedef struct _mwmhints
 
 // for speed reasons, we assume that all codepoints 32 to 126 are
 // single-width.
+#ifndef __QNXNTO__
 #define WCWIDTH(c)		(IN_RANGE_INC (c, 0x20, 0x7e) ? 1 : wcwidth (c))
+#else
+#define WCWIDTH(c)		(IN_RANGE_INC (c, 0x20, 0x7e) ? 1 : (iswprint(c) ? 1 : -1))
+#endif
 
 /* convert pixel dimensions to row/column values.  Everything as int32_t */
 #define Pixel2Col(x)            Pixel2Width((int32_t)(x))
