$NetBSD$

--- toolkit/mozapps/update/updater/updater.cpp.orig	2013-04-10 03:02:56.000000000 +0000
+++ toolkit/mozapps/update/updater/updater.cpp
@@ -3177,7 +3177,10 @@ int add_dir_entries(const NS_tchar *dirp
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
