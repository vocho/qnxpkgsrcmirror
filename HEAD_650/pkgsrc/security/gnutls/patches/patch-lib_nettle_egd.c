$NetBSD: patch-lib_nettle_egd.c,v 1.1 2011/05/02 09:27:44 obache Exp $

* for backward compatibility for lack of AF_LOCAL.

--- lib/nettle/egd.c.orig	2012-04-12 20:05:11.000000000 +0000
+++ lib/nettle/egd.c
@@ -47,6 +47,10 @@
 #define offsetof(type, member) ((size_t) &((type *)0)->member)
 #endif
 
+#ifndef AF_LOCAL
+#define AF_LOCAL AF_UNIX
+#endif
+
 static int egd_socket = -1;
 
 static int
