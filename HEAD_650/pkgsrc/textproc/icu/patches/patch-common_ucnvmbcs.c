$NetBSD$

--- common/ucnvmbcs.c.orig	2012-11-05 17:14:40.000000000 +0000
+++ common/ucnvmbcs.c
@@ -57,6 +57,9 @@
 #include "cmemory.h"
 #include "cstring.h"
 #include "umutex.h"
+#ifdef __QNXNTO__
+#undef si_value
+#endif
 
 /* control optimizations according to the platform */
 #define MBCS_UNROLL_SINGLE_TO_BMP 1
