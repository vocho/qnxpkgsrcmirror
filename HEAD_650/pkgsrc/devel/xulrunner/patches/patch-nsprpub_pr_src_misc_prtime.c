$NetBSD$

--- nsprpub/pr/src/misc/prtime.c.orig	2011-09-22 20:20:37.000000000 +0000
+++ nsprpub/pr/src/misc/prtime.c
@@ -52,6 +52,9 @@
 #include <ctype.h>
 #include <errno.h>  /* for EINVAL */
 #include <time.h>
+#ifdef __QNXNTO__
+#include <nbutil.h>
+#endif
 
 /* 
  * The COUNT_LEAPS macro counts the number of leap years passed by
