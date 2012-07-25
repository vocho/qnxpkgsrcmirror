$NetBSD$

--- js/src/jsgcchunk.cpp.orig	2012-03-13 01:36:55.000000000 +0000
+++ js/src/jsgcchunk.cpp
@@ -367,7 +367,11 @@ bool
 DecommitMemory(void *addr, size_t size)
 {
     JS_ASSERT(uintptr_t(addr) % 4096UL == 0);
+#ifndef __QNXNTO__
     int result = madvise(addr, size, MADV_DONTNEED);
+#else
+    int result = posix_madvise(addr, size, POSIX_MADV_DONTNEED);
+#endif
     return result != -1;
 }
 #else
