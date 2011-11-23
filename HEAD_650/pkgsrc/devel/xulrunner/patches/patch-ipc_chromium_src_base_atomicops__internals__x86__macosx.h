$NetBSD$

--- ipc/chromium/src/base/atomicops_internals_x86_macosx.h.orig	2011-08-11 21:41:01.000000000 +0000
+++ ipc/chromium/src/base/atomicops_internals_x86_macosx.h
@@ -7,10 +7,14 @@
 #ifndef BASE_ATOMICOPS_INTERNALS_X86_MACOSX_H_
 #define BASE_ATOMICOPS_INTERNALS_X86_MACOSX_H_
 
+#ifndef OS_QNX
 #include <libkern/OSAtomic.h>
+#endif
 
 namespace base {
 namespace subtle {
+#ifndef OS_QNX
+
 
 inline Atomic32 NoBarrier_CompareAndSwap(volatile Atomic32 *ptr,
                                          Atomic32 old_value,
@@ -189,6 +193,7 @@ inline Atomic64 Release_Load(volatile co
 }
 
 #endif  // defined(__LP64__)
+#endif // OS_QNX
 
 // MacOS uses long for intptr_t, AtomicWord and Atomic32 are always different
 // on the Mac, even when they are the same size.  We need to explicitly cast
