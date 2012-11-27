$NetBSD$

--- js/src/gc/Memory.cpp.orig	2012-07-13 21:42:56.000000000 +0000
+++ js/src/gc/Memory.cpp
@@ -325,7 +325,11 @@ bool
 MarkPagesUnused(void *p, size_t size)
 {
     JS_ASSERT(uintptr_t(p) % PageSize == 0);
+#ifndef __QNXNTO__
     int result = madvise(p, size, MADV_DONTNEED);
+#else
+    int result = posix_madvise(p, size, POSIX_MADV_DONTNEED);
+#endif
     return result != -1;
 }
 
