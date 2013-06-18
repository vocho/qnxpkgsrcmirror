$NetBSD: patch-ipc_chromium_src_base_platform__thread__posix.cc,v 1.10 2013/03/30 20:03:09 ryoon Exp $

--- ipc/chromium/src/base/platform_thread_posix.cc.orig	2013-04-10 03:01:46.000000000 +0000
+++ ipc/chromium/src/base/platform_thread_posix.cc
@@ -10,7 +10,11 @@
 #if defined(OS_MACOSX)
 #include <mach/mach.h>
 #elif defined(OS_NETBSD)
+_Pragma("GCC visibility push(default)")
 #include <lwp.h>
+_Pragma("GCC visibility pop")
+#elif defined(OS_QNX)
+/* Nothing */
 #elif defined(OS_LINUX)
 #include <sys/syscall.h>
 #include <sys/prctl.h>
@@ -50,6 +54,8 @@ PlatformThreadId PlatformThread::Current
   return _lwp_self();
 #elif defined(OS_DRAGONFLY)
   return lwp_gettid();
+#elif defined(OS_QNX)
+  return pthread_self();
 #elif defined(OS_FREEBSD)
 #  if __FreeBSD_version > 900030
     return pthread_getthreadid_np();
@@ -106,6 +112,8 @@ void PlatformThread::SetName(const char*
   pthread_set_name_np(pthread_self(), name);
 #elif defined(OS_NETBSD)
   pthread_setname_np(pthread_self(), "%s", (void *)name);
+#elif defined(OS_QNX)
+  pthread_setname_np(pthread_self(), name);
 #else
   prctl(PR_SET_NAME, reinterpret_cast<uintptr_t>(name), 0, 0, 0); 
 #endif
