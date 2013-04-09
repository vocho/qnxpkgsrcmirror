$NetBSD$

--- layout/base/nsPresArena.cpp.orig	2012-11-19 15:42:39.000000000 +0000
+++ layout/base/nsPresArena.cpp
@@ -144,7 +144,13 @@ ReleaseRegion(void *region, uintptr_t si
 static bool
 ProbeRegion(uintptr_t region, uintptr_t size)
 {
-  if (madvise((caddr_t)region, size, MADV_NORMAL)) {
+  int ret;
+#ifndef __QNXNTO__
+  ret = madvise((caddr_t)region, size, MADV_NORMAL);
+#else
+  ret = posix_madvise((caddr_t)region, size, POSIX_MADV_NORMAL);
+#endif
+  if (ret) {
     return true;
   } else {
     return false;
