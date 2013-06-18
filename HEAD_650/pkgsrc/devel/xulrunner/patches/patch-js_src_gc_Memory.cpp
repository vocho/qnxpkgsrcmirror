$NetBSD$

--- js/src/gc/Memory.cpp.orig	2013-04-10 03:01:49.000000000 +0000
+++ js/src/gc/Memory.cpp
@@ -371,7 +371,11 @@ gc::MarkPagesUnused(void *p, size_t size
         return false;
 
     JS_ASSERT(uintptr_t(p) % PageSize == 0);
+#ifndef __QNXNTO__
     int result = madvise(p, size, MADV_DONTNEED);
+#else
+    int result = posix_madvise(p, size, POSIX_MADV_DONTNEED);
+#endif
     return result != -1;
 }
 
