$NetBSD$

--- ipc/chromium/src/base/basictypes.h.orig	2011-08-11 21:41:01.000000000 +0000
+++ ipc/chromium/src/base/basictypes.h
@@ -33,8 +33,12 @@
 
 #include "obsolete/protypes.h"
 
+#ifndef _INT32
 #define _INT32
+#endif
+#ifndef _UINT32
 #define _UINT32
+#endif
 
 #ifdef _WIN32_SAVE
 #undef _WIN32_SAVE
