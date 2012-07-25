$NetBSD: patch-ipc_chromium_src_base_platform__thread.h,v 1.2 2012/05/08 19:29:36 martin Exp $

# Reported upstream: https://bugzilla.mozilla.org/show_bug.cgi?id=753046

--- ipc/chromium/src/base/platform_thread.h.orig	2012-04-20 22:03:52.000000000 +0000
+++ ipc/chromium/src/base/platform_thread.h
@@ -25,6 +25,10 @@ typedef pthread_t PlatformThreadHandle;
 #if defined(OS_LINUX)
 #include <unistd.h>
 typedef pid_t PlatformThreadId;
+#elif defined(OS_FREEBSD) || defined(OS_DRAGONFLY) || defined (OS_NETBSD)
+typedef lwpid_t PlatformThreadId;
+#elif defined(OS_QNX)
+typedef pthread_t PlatformThreadId;
 #elif defined(OS_MACOSX)
 #include <mach/mach.h>
 typedef mach_port_t PlatformThreadId;
