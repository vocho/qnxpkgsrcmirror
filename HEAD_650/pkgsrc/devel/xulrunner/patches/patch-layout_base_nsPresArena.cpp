$NetBSD$

--- layout/base/nsPresArena.cpp.orig	2013-04-10 03:01:59.000000000 +0000
+++ layout/base/nsPresArena.cpp
@@ -143,7 +143,13 @@ ReleaseRegion(void *region, uintptr_t si
 static bool
 ProbeRegion(uintptr_t region, uintptr_t size)
 {
-  if (madvise(reinterpret_cast<void*>(region), size, MADV_NORMAL)) {
+  int ret;
+#ifndef __QNXNTO__
+  ret = madvise(reinterpret_cast<void*>(region), size, MADV_NORMAL);
+#else
+  ret = posix_madvise(reinterpret_cast<void*>(region), size, POSIX_MADV_NORMAL);
+#endif
+  if (ret) {
     return true;
   } else {
     return false;
