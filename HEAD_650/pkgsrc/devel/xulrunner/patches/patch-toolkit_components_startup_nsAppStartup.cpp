$NetBSD$

--- toolkit/components/startup/nsAppStartup.cpp.orig	2011-08-11 21:41:30.000000000 +0000
+++ toolkit/components/startup/nsAppStartup.cpp
@@ -84,8 +84,10 @@
 #undef GetStartupInfo
 #elif defined(XP_UNIX)
 #include <unistd.h>
+#ifndef __QNXNTO__
 #include <sys/syscall.h>
 #endif
+#endif
 
 #ifdef XP_MACOSX
 #include <sys/sysctl.h>
