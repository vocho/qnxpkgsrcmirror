$NetBSD$

--- js/src/jsapi.h.orig	2012-05-09 18:02:11.000000000 +0000
+++ js/src/jsapi.h
@@ -2274,7 +2274,11 @@ class JS_PUBLIC_API(JSAutoEnterCompartme
      * In practice, 32-bit Windows and Android get 16-word |bytes|, while
      * other platforms get 13-word |bytes|.
      */
+#ifndef __QNXNTO__
     void* bytes[sizeof(void*) == 4 && MOZ_ALIGNOF(uint64_t) == 8 ? 16 : 13];
+#else
+    void* bytes[16];
+#endif
 
     /*
      * This object may be in one of three states.  If enter() or
