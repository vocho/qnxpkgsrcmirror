$NetBSD$

--- ipc/chromium/src/base/atomicops_internals_x86_gcc.h.orig	2011-08-11 21:41:01.000000000 +0000
+++ ipc/chromium/src/base/atomicops_internals_x86_gcc.h
@@ -256,6 +256,14 @@ inline Atomic64 Release_Load(volatile co
 } // namespace base::subtle
 } // namespace base
 
+#ifdef OS_QNX
+/*
+ * QNX has the same intprt_t / Atomic32 mismatch as MacOS so
+ * we need the same casting magic.
+ */
+#include "base/atomicops_internals_x86_macosx.h"
+#endif
+
 #undef ATOMICOPS_COMPILER_BARRIER
 
 #endif  // BASE_ATOMICOPS_INTERNALS_X86_GCC_H_
