$NetBSD$

--- xpcom/ds/nsMathUtils.h.orig	2011-08-11 21:41:32.000000000 +0000
+++ xpcom/ds/nsMathUtils.h
@@ -150,6 +150,8 @@ inline NS_HIDDEN_(bool) NS_finite(double
 #ifdef WIN32
     // NOTE: '!!' casts an int to bool without spamming MSVC warning C4800.
     return !!_finite(d);
+#elif defined(__QNXNTO__)
+    return isfinite(d);
 #else
     return finite(d);
 #endif
