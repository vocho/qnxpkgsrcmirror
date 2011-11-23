$NetBSD$

--- src/3rdparty/webkit/WebCore/bridge/npapi.h.orig	2011-03-30 05:18:50.000000000 +0000
+++ src/3rdparty/webkit/WebCore/bridge/npapi.h
@@ -128,13 +128,7 @@
 /*----------------------------------------------------------------------*/
 
 /* QNX sets the _INT16 and friends defines, but does not typedef the types */
-#ifdef __QNXNTO__
-#undef _UINT16
-#undef _INT16
-#undef _UINT32
-#undef _INT32
-#endif
-
+#ifndef __QNXNTO__
 #ifndef _UINT16
 #define _UINT16
 typedef unsigned short uint16;
@@ -162,6 +156,12 @@ typedef int int32;
 typedef long int32;
 #endif /* __LP64__ */
 #endif
+#else
+typedef _Uint16t uint16;
+typedef _Uint32t uint32;
+typedef _Int16t int16;
+typedef _Int32t int32;
+#endif
 
 #ifndef FALSE
 #define FALSE (0)
