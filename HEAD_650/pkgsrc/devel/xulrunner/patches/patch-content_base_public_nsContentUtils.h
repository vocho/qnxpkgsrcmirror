$NetBSD$

--- content/base/public/nsContentUtils.h.orig	2011-04-14 05:28:22.000000000 +0000
+++ content/base/public/nsContentUtils.h
@@ -1941,6 +1941,8 @@ private:
 inline NS_HIDDEN_(PRBool) NS_FloatIsFinite(jsdouble f) {
 #ifdef WIN32
   return _finite(f);
+#elif defined(__QNXNTO__)
+  return isfinite(f);
 #else
   return finite(f);
 #endif
