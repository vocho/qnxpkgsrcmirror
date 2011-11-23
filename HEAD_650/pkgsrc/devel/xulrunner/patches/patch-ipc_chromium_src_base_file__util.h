$NetBSD: patch-ipc_chromium_src_base_file__util.h,v 1.1 2011/07/11 12:46:14 tnn Exp $

--- ipc/chromium/src/base/file_util.h.orig	2011-08-11 21:41:01.000000000 +0000
+++ ipc/chromium/src/base/file_util.h
@@ -12,11 +12,12 @@
 
 #if defined(OS_WIN)
 #include <windows.h>
-#elif defined(ANDROID)
+#elif defined(ANDROID) || defined(OS_QNX)
 #include <sys/stat.h>
 #elif defined(OS_POSIX) 
-#include <fts.h>
+#include <sys/types.h>
 #include <sys/stat.h>
+#include <fts.h>
 #endif
 
 #include <stdio.h>
@@ -465,9 +466,9 @@ class FileEnumerator {
 #if defined(OS_WIN)
   WIN32_FIND_DATA find_data_;
   HANDLE find_handle_;
-#elif defined(ANDROID)
+#elif defined(ANDROID) || defined(OS_QNX)
   void *fts_;
-#elif defined(OS_POSIX)
+#elif defined(OS_POSIX) /* fts isn't POSIX BTW */
   FTS* fts_;
   FTSENT* fts_ent_;
 #endif
