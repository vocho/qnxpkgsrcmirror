$NetBSD$

--- git-compat-util.h.orig	2012-03-05 22:42:15.000000000 +0000
+++ git-compat-util.h
@@ -74,7 +74,7 @@
 # define _XOPEN_SOURCE 500
 # endif
 #elif !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__USLC__) && \
-      !defined(_M_UNIX) && !defined(__sgi) && !defined(__DragonFly__)
+      !defined(_M_UNIX) && !defined(__sgi) && !defined(__DragonFly__) && !defined(__QNXNTO__)
 #define _XOPEN_SOURCE 600 /* glibc2 and AIX 5.3L need 500, OpenBSD needs 600 for S_ISLNK() */
 #define _XOPEN_SOURCE_EXTENDED 1 /* AIX 5.3L needs this */
 #endif
@@ -150,6 +150,9 @@
 #undef _ALL_SOURCE /* AIX 5.3L defines a struct list with _ALL_SOURCE. */
 #include <grp.h>
 #define _ALL_SOURCE 1
+#if defined(__QNXNTO__)
+#include "compat/qnxnto.h"
+#endif
 #endif
 #endif
 
