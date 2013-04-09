$NetBSD: patch-ipc_chromium_src_base_process__util__posix.cc,v 1.4 2012/08/28 23:27:10 ryoon Exp $

--- ipc/chromium/src/base/process_util_posix.cc.orig	2012-11-19 15:42:29.000000000 +0000
+++ ipc/chromium/src/base/process_util_posix.cc
@@ -116,6 +116,11 @@ void CloseSuperfluousFds(const base::Inj
 #elif defined(OS_MACOSX)
   static const rlim_t kSystemDefaultMaxFds = 256;
   static const char kFDDir[] = "/dev/fd";
+#elif defined(OS_BSD) || defined(OS_QNX)
+  // the getrlimit below should never fail, so whatever ..
+  static const rlim_t kSystemDefaultMaxFds = 1024;
+  // at least /dev/fd will exist
+  static const char kFDDir[] = "/dev/fd";
 #endif
 
   // Get the maximum number of FDs possible.
@@ -197,9 +202,10 @@ void CloseSuperfluousFds(const base::Inj
 // TODO(agl): Remove this function. It's fundamentally broken for multithreaded
 // apps.
 void SetAllFDsToCloseOnExec() {
+#if !defined(OS_QNX)
 #if defined(OS_LINUX)
   const char fd_dir[] = "/proc/self/fd";
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_BSD)
   const char fd_dir[] = "/dev/fd";
 #endif
   ScopedDIR dir_closer(opendir(fd_dir));
@@ -224,6 +230,17 @@ void SetAllFDsToCloseOnExec() {
       DLOG(ERROR) << "fcntl failure.";
     }
   }
+#else
+
+  int i, flags;
+
+  for (i = STDERR_FILENO + 1; i < 1024; i++) {
+    int flags = fcntl(i, F_GETFD);
+    if (flags == -1)
+      continue;
+   fcntl(i, F_SETFD, flags | FD_CLOEXEC);
+  }
+#endif
 }
 
 ProcessMetrics::ProcessMetrics(ProcessHandle process) : process_(process),
