$NetBSD$

--- toolkit/components/startup/nsAppStartup.cpp.orig	2013-04-10 03:02:51.000000000 +0000
+++ toolkit/components/startup/nsAppStartup.cpp
@@ -46,8 +46,10 @@
 #undef GetStartupInfo
 #elif defined(XP_UNIX)
 #include <unistd.h>
+#ifndef __QNXNTO__
 #include <sys/syscall.h>
 #endif
+#endif
 
 #if defined(XP_MACOSX) || defined(__DragonFly__) || defined(__FreeBSD__) \
   || defined(__NetBSD__) || defined(__OpenBSD__)
