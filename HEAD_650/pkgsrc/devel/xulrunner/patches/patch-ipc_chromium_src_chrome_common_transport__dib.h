$NetBSD$

--- ipc/chromium/src/chrome/common/transport_dib.h.orig	2013-04-10 03:01:47.000000000 +0000
+++ ipc/chromium/src/chrome/common/transport_dib.h
@@ -7,7 +7,7 @@
 
 #include "base/basictypes.h"
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD) || defined(OS_QNX)
 #include "base/shared_memory.h"
 #endif
 
@@ -66,7 +66,7 @@ class TransportDIB {
     uint32_t sequence_num;
   };
   typedef HandleAndSequenceNum Id;
-#elif defined(OS_MACOSX) || defined(OS_BSD)
+#elif defined(OS_MACOSX) || defined(OS_BSD) || defined(OS_QNX)
   typedef base::SharedMemoryHandle Handle;
   // On Mac, the inode number of the backing file is used as an id.
   typedef base::SharedMemoryId Id;
@@ -108,7 +108,7 @@ class TransportDIB {
 
  private:
   TransportDIB();
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD) || defined(OS_QNX)
   explicit TransportDIB(base::SharedMemoryHandle dib);
   base::SharedMemory shared_memory_;
 #elif defined(OS_LINUX)
