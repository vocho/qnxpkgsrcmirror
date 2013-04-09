$NetBSD$

--- memory/mozalloc/mozalloc_abort.cpp.orig	2012-11-19 15:43:07.000000000 +0000
+++ memory/mozalloc/mozalloc_abort.cpp
@@ -27,9 +27,15 @@ mozalloc_abort(const char* const msg)
 // Define abort() here, so that it is used instead of the system abort(). This
 // lets us control the behavior when aborting, in order to get better results
 // on *NIX platforms. See mozalloc_abort for details.
+#ifdef __QNXNTO__
+_C_STD_BEGIN
+#endif
 void abort(void)
 {
     mozalloc_abort("Redirecting call to abort() to mozalloc_abort\n");
 }
+#ifdef __QNXNTO__
+_C_STD_END
+#endif
 #endif
 
