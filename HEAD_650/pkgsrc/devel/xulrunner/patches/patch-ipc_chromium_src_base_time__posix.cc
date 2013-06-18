$NetBSD$

--- ipc/chromium/src/base/time_posix.cc.orig	2013-04-10 03:01:46.000000000 +0000
+++ ipc/chromium/src/base/time_posix.cc
@@ -7,6 +7,9 @@
 #ifdef OS_MACOSX
 #include <mach/mach_time.h>
 #endif
+#ifdef OS_QNX
+#include <nbutil.h>
+#endif
 #include <sys/time.h>
 #ifdef ANDROID
 #include <time64.h>
