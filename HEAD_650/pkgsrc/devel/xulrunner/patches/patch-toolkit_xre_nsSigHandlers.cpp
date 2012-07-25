$NetBSD$

--- toolkit/xre/nsSigHandlers.cpp.orig	2012-03-13 01:37:19.000000000 +0000
+++ toolkit/xre/nsSigHandlers.cpp
@@ -273,7 +273,13 @@ void InstallSignalHandlers(const char *P
 #ifdef SA_SIGINFO
   /* Install a handler for floating point exceptions and disable them if they occur. */
   struct sigaction sa, osa;
-  sa.sa_flags = SA_ONSTACK | SA_RESTART | SA_SIGINFO;
+  sa.sa_flags = SA_SIGINFO;
+#ifdef SA_ONSTACK
+  sa.sa_flags |= SA_ONSTACK;
+#endif
+#ifdef SA_RESTART
+  sa.sa_flags |= SA_RESTART;
+#endif
   sa.sa_sigaction = fpehandler;
   sigemptyset(&sa.sa_mask);
   sigaction(SIGFPE, &sa, &osa);
