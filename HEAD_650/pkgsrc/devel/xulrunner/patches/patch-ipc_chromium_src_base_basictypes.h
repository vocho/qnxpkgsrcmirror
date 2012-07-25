$NetBSD$

--- ipc/chromium/src/base/basictypes.h.orig	2012-03-13 01:36:53.000000000 +0000
+++ ipc/chromium/src/base/basictypes.h
@@ -31,8 +31,12 @@
 
 #include "obsolete/protypes.h"
 
+#ifndef _INT32
 #define _INT32
+#endif
+#ifndef _UINT32
 #define _UINT32
+#endif
 
 #ifdef _WIN32_SAVE
 #undef _WIN32_SAVE
