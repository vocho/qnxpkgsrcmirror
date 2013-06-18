$NetBSD$

--- ipc/chromium/src/base/process_util.h.orig	2013-04-10 03:01:46.000000000 +0000
+++ ipc/chromium/src/base/process_util.h
@@ -315,7 +315,7 @@ class NamedProcessIterator {
   bool started_iteration_;
 #elif defined(OS_LINUX)
   DIR *procfs_dir_;
-#elif defined(OS_BSD)
+#elif defined(OS_BSD) || defined(OS_QNX)
   std::vector<ProcessEntry> content;
   size_t nextEntry;
 #elif defined(OS_MACOSX)
