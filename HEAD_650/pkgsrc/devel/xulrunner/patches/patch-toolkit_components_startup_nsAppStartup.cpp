$NetBSD$

--- toolkit/components/startup/nsAppStartup.cpp.orig	2012-11-19 15:43:24.000000000 +0000
+++ toolkit/components/startup/nsAppStartup.cpp
@@ -47,8 +47,10 @@
 #undef GetStartupInfo
 #elif defined(XP_UNIX)
 #include <unistd.h>
+#ifndef __QNXNTO__
 #include <sys/syscall.h>
 #endif
+#endif
 
 #ifdef XP_MACOSX
 #include <sys/sysctl.h>
