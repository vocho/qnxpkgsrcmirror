$NetBSD$

--- Python/pythonrun.c.orig	2011-06-11 15:48:52.000000000 +0000
+++ Python/pythonrun.c
@@ -32,6 +32,9 @@
 #include <locale.h>
 #include <langinfo.h>
 #endif
+#ifdef HAVE_SETLOCALE
+#include <locale.h>
+#endif
 
 #ifdef MS_WINDOWS
 #undef BYTE
