$NetBSD$

--- libdaemon/dexec.c.orig	2009-04-20 00:58:07.000000000 +0000
+++ libdaemon/dexec.c
@@ -35,6 +35,9 @@
 #include <stdio.h>
 #include <stdarg.h>
 #include <assert.h>
+#ifdef __QNXNTO__
+#include <sys/select.h>
+#endif
 
 #include "dlog.h"
 #include "dsignal.h"
