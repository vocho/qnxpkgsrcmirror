$NetBSD$

--- toolkit/mozapps/update/common/updatedefines.h.orig	2012-04-20 22:04:10.000000000 +0000
+++ toolkit/mozapps/update/common/updatedefines.h
@@ -112,7 +112,9 @@
 #else
 # include <sys/wait.h>
 # include <unistd.h>
+#ifndef __QNXNTO__
 # include <fts.h>
+#endif
 
 #ifdef XP_MACOSX
 # include <sys/time.h>
