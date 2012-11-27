$NetBSD: patch-gl_stdio.in.h,v 1.1 2012/08/02 09:37:32 jperkin Exp $

Avoid conflict between gets() and std::gets()

--- gl/stdio.in.h.orig	2012-06-05 17:07:53.000000000 +0000
+++ gl/stdio.in.h
@@ -699,6 +699,7 @@ _GL_WARN_ON_USE (getline, "getline is un
 # endif
 #endif
 
+#if !(defined __cplusplus)
 /* It is very rare that the developer ever has full control of stdin,
    so any use of gets warrants an unconditional warning; besides, C11
    removed it.  */
@@ -706,6 +707,7 @@ _GL_WARN_ON_USE (getline, "getline is un
 #if HAVE_RAW_DECL_GETS
 _GL_WARN_ON_USE (gets, "gets is a security hole - use fgets instead");
 #endif
+#endif
 
 
 #if @GNULIB_OBSTACK_PRINTF@ || @GNULIB_OBSTACK_PRINTF_POSIX@
