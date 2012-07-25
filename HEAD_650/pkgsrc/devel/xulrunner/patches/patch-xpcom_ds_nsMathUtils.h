$NetBSD$

--- xpcom/ds/nsMathUtils.h.orig	2012-05-24 14:10:56.000000000 +0000
+++ xpcom/ds/nsMathUtils.h
@@ -130,7 +130,7 @@ inline NS_HIDDEN_(bool) NS_finite(double
 #ifdef WIN32
     // NOTE: '!!' casts an int to bool without spamming MSVC warning C4800.
     return !!_finite(d);
-#elif defined(XP_DARWIN)
+#elif defined(XP_DARWIN) || defined(__QNXNTO__)
     // Darwin has deprecated |finite| and recommends |isfinite|. The former is
     // not present in the iOS SDK.
     return std::isfinite(d);
