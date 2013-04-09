$NetBSD$

--- toolkit/mozapps/update/common/updatedefines.h.orig	2012-11-19 15:43:27.000000000 +0000
+++ toolkit/mozapps/update/common/updatedefines.h
@@ -104,7 +104,7 @@ static int mywcsprintf(WCHAR* dest, size
 # include <sys/wait.h>
 # include <unistd.h>
 
-#ifdef SOLARIS
+#if defined(SOLARIS) || defined(__QNXNTO__)
 # include <sys/stat.h>
 #else
 # include <fts.h>
