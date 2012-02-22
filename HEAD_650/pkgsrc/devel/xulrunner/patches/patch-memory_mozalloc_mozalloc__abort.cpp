$NetBSD$

--- memory/mozalloc/mozalloc_abort.cpp.orig	2011-11-04 21:34:12.000000000 +0000
+++ memory/mozalloc/mozalloc_abort.cpp
@@ -103,9 +103,15 @@ mozalloc_abort(const char* const msg)
 // Define abort() here, so that it is used instead of the system abort(). This
 // lets us control the behavior when aborting, in order to get better results
 // on *NIX platfrorms. See mozalloc_abort for details.
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
 
