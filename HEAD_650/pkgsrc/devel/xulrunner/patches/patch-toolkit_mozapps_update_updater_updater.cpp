$NetBSD$

--- toolkit/mozapps/update/updater/updater.cpp.orig	2012-04-20 22:04:10.000000000 +0000
+++ toolkit/mozapps/update/updater/updater.cpp
@@ -2380,6 +2380,7 @@ int add_dir_entries(const NS_tchar *dirp
 
 int add_dir_entries(const NS_tchar *dirpath, ActionList *list)
 {
+#ifndef __QNXNTO__
   int rv = OK;
   FTS *ftsdir;
   FTSENT *ftsdirEntry;
@@ -2485,6 +2486,9 @@ int add_dir_entries(const NS_tchar *dirp
   fts_close(ftsdir);
 
   return rv;
+#else
+  return UNEXPECTED_ERROR;
+#endif
 }
 #endif
 
