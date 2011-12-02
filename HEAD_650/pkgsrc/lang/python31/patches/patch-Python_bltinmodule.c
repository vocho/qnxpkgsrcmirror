$NetBSD$

--- Python/bltinmodule.c.orig	2011-06-11 15:48:52.000000000 +0000
+++ Python/bltinmodule.c
@@ -18,7 +18,7 @@
 #if defined(MS_WINDOWS) && defined(HAVE_USABLE_WCHAR_T)
 const char *Py_FileSystemDefaultEncoding = "mbcs";
 int Py_HasFileSystemDefaultEncoding = 1;
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__QNXNTO__)
 const char *Py_FileSystemDefaultEncoding = "utf-8";
 int Py_HasFileSystemDefaultEncoding = 1;
 #else
