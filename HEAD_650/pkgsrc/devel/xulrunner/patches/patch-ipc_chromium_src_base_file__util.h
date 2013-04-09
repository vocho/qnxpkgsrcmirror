$NetBSD$

--- ipc/chromium/src/base/file_util.h.orig	2012-11-19 15:42:29.000000000 +0000
+++ ipc/chromium/src/base/file_util.h
@@ -12,7 +12,7 @@
 
 #if defined(OS_WIN)
 #include <windows.h>
-#elif defined(ANDROID)
+#elif defined(ANDROID) || defined(OS_QNX)
 #include <sys/stat.h>
 #elif defined(OS_POSIX) 
 #include <sys/types.h>
@@ -466,9 +466,9 @@ class FileEnumerator {
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
