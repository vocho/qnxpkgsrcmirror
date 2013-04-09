$NetBSD$

--- ipc/chromium/src/base/platform_thread.h.orig	2012-11-19 15:42:29.000000000 +0000
+++ ipc/chromium/src/base/platform_thread.h
@@ -22,12 +22,16 @@ typedef void* PlatformThreadHandle;  // 
 #elif defined(OS_POSIX)
 #include <pthread.h>
 typedef pthread_t PlatformThreadHandle;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_OPENBSD)
 #include <unistd.h>
 typedef pid_t PlatformThreadId;
+#elif defined(OS_BSD)
+typedef lwpid_t PlatformThreadId;
 #elif defined(OS_MACOSX)
 #include <mach/mach.h>
 typedef mach_port_t PlatformThreadId;
+#elif defined(OS_QNX)
+typedef pthread_t PlatformThreadId;
 #endif
 #endif
 
