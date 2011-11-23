$NetBSD$

--- ipc/chromium/src/base/third_party/nspr/prtime.cc.orig	2011-08-11 21:41:01.000000000 +0000
+++ ipc/chromium/src/base/third_party/nspr/prtime.cc
@@ -70,6 +70,8 @@
 #include <windows.h>
 #elif defined(OS_MACOSX)
 #include <CoreFoundation/CoreFoundation.h>
+#elif defined(OS_QNX)
+#include <nbutil.h> /* timegm() */
 #endif
 #include <errno.h>  /* for EINVAL */
 #include <time.h>
