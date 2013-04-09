$NetBSD$

--- gfx/skia/include/core/SkPreConfig.h.orig	2012-11-19 15:42:23.000000000 +0000
+++ gfx/skia/include/core/SkPreConfig.h
@@ -36,7 +36,7 @@
         #define SK_BUILD_FOR_ANDROID
     #elif defined(linux) || defined(__FreeBSD__) || defined(__OpenBSD__) || \
           defined(__sun) || defined(__NetBSD__) || defined(__DragonFly__) || \
-          defined(__GLIBC__) || defined(__GNU__)
+          defined(__GLIBC__) || defined(__GNU__) || defined(__QNXNTO__)
         #define SK_BUILD_FOR_UNIX
     #elif TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
         #define SK_BUILD_FOR_IOS
