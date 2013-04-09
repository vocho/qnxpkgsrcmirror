$NetBSD$

--- toolkit/mozapps/update/updater/updater.cpp.orig	2012-11-19 15:43:27.000000000 +0000
+++ toolkit/mozapps/update/updater/updater.cpp
@@ -3098,7 +3098,10 @@ int add_dir_entries(const NS_tchar *dirp
   return rv;
 }
 
-#elif defined(SOLARIS)
+#elif defined(SOLARIS) || defined(__QNXNTO__)
+#ifndef MAXNAMLEN
+#define MAXNAMLEN NAME_MAX
+#endif
 int add_dir_entries(const NS_tchar *dirpath, ActionList *list)
 {
   int rv = OK;
