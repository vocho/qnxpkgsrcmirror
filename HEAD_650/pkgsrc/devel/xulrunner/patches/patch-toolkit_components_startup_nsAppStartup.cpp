$NetBSD$

--- toolkit/components/startup/nsAppStartup.cpp.orig	2012-03-13 01:37:15.000000000 +0000
+++ toolkit/components/startup/nsAppStartup.cpp
@@ -81,8 +81,10 @@
 #undef GetStartupInfo
 #elif defined(XP_UNIX)
 #include <unistd.h>
+#ifndef __QNXNTO__
 #include <sys/syscall.h>
 #endif
+#endif
 
 #ifdef XP_MACOSX
 #include <sys/sysctl.h>
