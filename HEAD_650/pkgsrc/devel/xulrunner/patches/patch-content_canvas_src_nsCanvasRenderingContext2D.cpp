$NetBSD$

--- content/canvas/src/nsCanvasRenderingContext2D.cpp.orig	2011-04-14 05:28:22.000000000 +0000
+++ content/canvas/src/nsCanvasRenderingContext2D.cpp
@@ -158,6 +158,8 @@ DoubleIsFinite(double d)
 #ifdef WIN32
     // NOTE: '!!' casts an int to bool without spamming MSVC warning C4800.
     return !!_finite(d);
+#elif defined(__QNXNTO__)
+    return isfinite(d);
 #else
     return finite(d);
 #endif
