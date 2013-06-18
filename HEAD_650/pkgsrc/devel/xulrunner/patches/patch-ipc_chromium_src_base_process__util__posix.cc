$NetBSD$

--- ipc/chromium/src/base/process_util_posix.cc.orig	2013-04-10 03:01:46.000000000 +0000
+++ ipc/chromium/src/base/process_util_posix.cc
@@ -116,7 +116,7 @@ void CloseSuperfluousFds(const base::Inj
 #elif defined(OS_MACOSX)
   static const rlim_t kSystemDefaultMaxFds = 256;
   static const char kFDDir[] = "/dev/fd";
-#elif defined(OS_BSD)
+#elif defined(OS_BSD) || defined(OS_QNX)
   // the getrlimit below should never fail, so whatever ..
   static const rlim_t kSystemDefaultMaxFds = 1024;
   // at least /dev/fd will exist
@@ -202,6 +202,7 @@ void CloseSuperfluousFds(const base::Inj
 // TODO(agl): Remove this function. It's fundamentally broken for multithreaded
 // apps.
 void SetAllFDsToCloseOnExec() {
+#if !defined(OS_QNX)
 #if defined(OS_LINUX)
   const char fd_dir[] = "/proc/self/fd";
 #elif defined(OS_MACOSX) || defined(OS_BSD)
@@ -229,6 +230,17 @@ void SetAllFDsToCloseOnExec() {
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
