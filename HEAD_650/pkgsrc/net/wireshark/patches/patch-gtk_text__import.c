$NetBSD$

--- gtk/text_import.c.orig	2011-07-18 20:16:42.000000000 +0000
+++ gtk/text_import.c
@@ -84,12 +84,14 @@
  * (needed for glibc 2.2) but make sure we do this only if not
  * yet defined.
  */
+#ifndef __QNXNTO__
 #ifndef __USE_XOPEN
 #  define __USE_XOPEN
 #endif
 #ifndef _XOPEN_SOURCE
 #  define _XOPEN_SOURCE
 #endif
+#endif
 
 /*
  * Defining _XOPEN_SOURCE is needed on some platforms, e.g. platforms
