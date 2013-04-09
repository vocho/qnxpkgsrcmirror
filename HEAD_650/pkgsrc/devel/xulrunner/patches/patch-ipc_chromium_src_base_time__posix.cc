$NetBSD: patch-ipc_chromium_src_base_time__posix.cc,v 1.2 2012/08/28 23:27:10 ryoon Exp $

--- ipc/chromium/src/base/time_posix.cc.orig	2012-11-19 15:42:29.000000000 +0000
+++ ipc/chromium/src/base/time_posix.cc
@@ -7,6 +7,9 @@
 #ifdef OS_MACOSX
 #include <mach/mach_time.h>
 #endif
+#ifdef OS_QNX
+#include <nbutil.h>
+#endif
 #include <sys/time.h>
 #ifdef ANDROID
 #include <time64.h>
@@ -167,7 +170,7 @@ TimeTicks TimeTicks::Now() {
   // With numer and denom = 1 (the expected case), the 64-bit absolute time
   // reported in nanoseconds is enough to last nearly 585 years.
 
-#elif defined(__OpenBSD__) || defined(OS_POSIX) && \
+#elif defined(OS_OPENBSD) || defined(OS_POSIX) && \
       defined(_POSIX_MONOTONIC_CLOCK) && _POSIX_MONOTONIC_CLOCK >= 0
 
   struct timespec ts;
