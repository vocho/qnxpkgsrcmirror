$NetBSD$

--- gl/strerror-override.h.orig	2012-06-05 17:07:53.000000000 +0000
+++ gl/strerror-override.h
@@ -49,7 +49,9 @@
      || GNULIB_defined_ENOTRECOVERABLE
 extern const char *strerror_override (int errnum);
 # else
+#ifndef __QNXNTO__
 #  define strerror_override(ignored) NULL
+#endif
 # endif
 
 #endif /* _GL_STRERROR_OVERRIDE_H */
