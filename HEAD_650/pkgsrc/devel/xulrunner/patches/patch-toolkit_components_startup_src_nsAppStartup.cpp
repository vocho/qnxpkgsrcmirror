$NetBSD$

--- toolkit/components/startup/src/nsAppStartup.cpp.orig	2011-04-14 05:28:47.000000000 +0000
+++ toolkit/components/startup/src/nsAppStartup.cpp
@@ -83,8 +83,10 @@
 #undef GetStartupInfo
 #elif defined(XP_UNIX)
 #include <unistd.h>
+#ifndef __QNXNTO__
 #include <sys/syscall.h>
 #endif
+#endif
 
 #ifdef XP_MACOSX
 #include <sys/sysctl.h>
