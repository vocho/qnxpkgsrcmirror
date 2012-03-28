$NetBSD$

--- gio/libasyncns/asyncns.c.orig	2011-11-11 17:56:52.000000000 +0000
+++ gio/libasyncns/asyncns.c
@@ -71,6 +71,10 @@
 #define MSG_NOSIGNAL 0
 #endif
 
+#if defined(__QNXNTO__) && !defined(NSIG)
+#define NSIG  _NSIG
+#endif
+
 #define MAX_WORKERS 16
 #define MAX_QUERIES 256
 #define BUFSIZE (10240)
