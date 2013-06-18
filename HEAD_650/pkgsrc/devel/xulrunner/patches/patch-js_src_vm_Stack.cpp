$NetBSD$

--- js/src/vm/Stack.cpp.orig	2013-04-10 03:01:58.000000000 +0000
+++ js/src/vm/Stack.cpp
@@ -805,7 +805,12 @@ StackSpace::sizeOf()
 #endif
 
     MincoreArgType *vec = (MincoreArgType *) js_malloc(numPages);
+#ifndef __QNXNTO__
     int result = mincore(base_, numBytes, vec);
+#else
+    int result = 0;
+    memset(vec, 0xff, numPages);
+#endif
     if (result) {
         js_free(vec);
         /*
