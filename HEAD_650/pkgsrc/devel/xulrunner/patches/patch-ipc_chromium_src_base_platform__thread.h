$NetBSD$

--- ipc/chromium/src/base/platform_thread.h.orig	2013-04-10 03:01:46.000000000 +0000
+++ ipc/chromium/src/base/platform_thread.h
@@ -31,6 +31,8 @@ typedef lwpid_t PlatformThreadId;
 #elif defined(OS_MACOSX)
 #include <mach/mach.h>
 typedef mach_port_t PlatformThreadId;
+#elif defined(OS_QNX)
+typedef pthread_t PlatformThreadId;
 #endif
 #endif
 
