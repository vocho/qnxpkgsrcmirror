$NetBSD$

--- toolkit/mozapps/update/updater/updater.cpp.orig	2011-08-11 21:41:31.000000000 +0000
+++ toolkit/mozapps/update/updater/updater.cpp
@@ -127,7 +127,9 @@
 #else
 # include <sys/wait.h>
 # include <unistd.h>
+#ifndef __QNXNTO__
 # include <fts.h>
+#endif
 
 #ifdef XP_MACOSX
 # include <sys/time.h>
@@ -2234,6 +2236,7 @@ int add_dir_entries(const NS_tchar *dirp
 
 int add_dir_entries(const NS_tchar *dirpath, ActionList *list)
 {
+#ifndef __QNXNTO__
   int rv = OK;
   FTS *ftsdir;
   FTSENT *ftsdirEntry;
@@ -2339,6 +2342,9 @@ int add_dir_entries(const NS_tchar *dirp
   fts_close(ftsdir);
 
   return rv;
+#else
+  return UNEXPECTED_ERROR;
+#endif
 }
 #endif
 
