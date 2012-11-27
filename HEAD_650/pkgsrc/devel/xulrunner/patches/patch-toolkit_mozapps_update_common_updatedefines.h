$NetBSD$

--- toolkit/mozapps/update/common/updatedefines.h.orig	2012-07-13 21:43:16.000000000 +0000
+++ toolkit/mozapps/update/common/updatedefines.h
@@ -113,7 +113,7 @@
 # include <sys/wait.h>
 # include <unistd.h>
 
-#ifdef SOLARIS
+#if defined(SOLARIS) || defined(__QNXNTO__)
 # include <sys/stat.h>
 # include <dirent.h>
 #else
