$NetBSD$

--- Modules/_ctypes/ctypes.h.orig	2011-06-11 15:48:51.000000000 +0000
+++ Modules/_ctypes/ctypes.h
@@ -3,8 +3,12 @@
 #endif
 
 #ifndef MS_WIN32
+#ifndef max
 #define max(a, b) ((a) > (b) ? (a) : (b))
+#endif
+#ifndef min
 #define min(a, b) ((a) < (b) ? (a) : (b))
+#endif
 
 #define PARAMFLAG_FIN 0x1
 #define PARAMFLAG_FOUT 0x2
