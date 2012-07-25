$NetBSD$

--- gfx/skia/include/core/SkPreConfig.h.orig	2012-04-20 22:03:50.000000000 +0000
+++ gfx/skia/include/core/SkPreConfig.h
@@ -31,7 +31,7 @@
     #elif defined(__SYMBIAN32__)
         #define SK_BUILD_FOR_WIN32
     #elif defined(linux) || defined(__FreeBSD__) || defined(__OpenBSD__) || \
-          defined(__sun) || defined(__NetBSD__) || defined(__DragonFly__)
+          defined(__sun) || defined(__NetBSD__) || defined(__DragonFly__) || defined(__QNXNTO__)
         #define SK_BUILD_FOR_UNIX
     #elif TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
         #define SK_BUILD_FOR_IOS
