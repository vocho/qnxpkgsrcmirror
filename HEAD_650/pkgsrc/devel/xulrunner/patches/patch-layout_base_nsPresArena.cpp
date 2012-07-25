$NetBSD$

--- layout/base/nsPresArena.cpp.orig	2012-03-13 01:37:00.000000000 +0000
+++ layout/base/nsPresArena.cpp
@@ -178,7 +178,13 @@ ReleaseRegion(void *region, PRUword size
 static bool
 ProbeRegion(PRUword region, PRUword size)
 {
-  if (madvise((caddr_t)region, size, MADV_NORMAL)) {
+  if (
+#ifndef __QNXNTO__
+    madvise((caddr_t)region, size, MADV_NORMAL)
+#else
+    posix_madvise((caddr_t)region, size, POSIX_MADV_NORMAL)
+#endif
+    ) {
     return true;
   } else {
     return false;
