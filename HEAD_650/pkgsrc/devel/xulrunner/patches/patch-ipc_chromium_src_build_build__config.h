$NetBSD$

--- ipc/chromium/src/build/build_config.h.orig	2013-04-10 03:01:47.000000000 +0000
+++ ipc/chromium/src/build/build_config.h
@@ -29,6 +29,8 @@
 #define OS_OPENBSD 1
 #elif defined(_WIN32)
 #define OS_WIN 1
+#elif defined(__QNXNTO__)
+#define OS_QNX 1
 #else
 #error Please add support for your platform in build/build_config.h
 #endif
@@ -42,7 +44,7 @@
 
 // For access to standard POSIX features, use OS_POSIX instead of a more
 // specific macro.
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || defined(OS_QNX)
 #define OS_POSIX 1
 #endif
 
