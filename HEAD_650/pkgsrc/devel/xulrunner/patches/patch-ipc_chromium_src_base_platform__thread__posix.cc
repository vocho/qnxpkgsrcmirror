$NetBSD: patch-ipc_chromium_src_base_platform__thread__posix.cc,v 1.2 2011/08/01 08:17:17 tnn Exp $

--- ipc/chromium/src/base/platform_thread_posix.cc.orig	2011-08-11 21:41:01.000000000 +0000
+++ ipc/chromium/src/base/platform_thread_posix.cc
@@ -9,6 +9,10 @@
 
 #if defined(OS_MACOSX)
 #include <mach/mach.h>
+#elif defined(OS_NETBSD)
+#include <lwp.h>
+#elif defined(OS_QNX)
+/* nothing */
 #elif defined(OS_LINUX)
 #include <sys/syscall.h>
 #include <unistd.h>
@@ -33,6 +37,12 @@ PlatformThreadId PlatformThread::Current
   // into the kernel.
 #if defined(OS_MACOSX)
   return mach_thread_self();
+#elif defined(OS_NETBSD)
+  return _lwp_self();
+#elif defined(OS_DRAGONFLY)
+  return lwp_gettid();
+#elif defined(OS_QNX)
+  return pthread_self();
 #elif defined(OS_LINUX)
   return syscall(__NR_gettid);
 #endif
