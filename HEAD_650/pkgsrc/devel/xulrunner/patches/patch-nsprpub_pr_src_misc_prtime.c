$NetBSD$

--- nsprpub/pr/src/misc/prtime.c.orig	2012-11-19 15:43:15.000000000 +0000
+++ nsprpub/pr/src/misc/prtime.c
@@ -20,6 +20,9 @@
 #include <ctype.h>
 #include <errno.h>  /* for EINVAL */
 #include <time.h>
+#ifdef __QNXNTO__
+#include <nbutil.h>
+#endif
 
 /* 
  * The COUNT_LEAPS macro counts the number of leap years passed by
