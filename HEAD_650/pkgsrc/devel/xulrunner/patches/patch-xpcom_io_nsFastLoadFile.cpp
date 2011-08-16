$NetBSD$

--- xpcom/io/nsFastLoadFile.cpp.orig	2011-04-14 05:28:50.000000000 +0000
+++ xpcom/io/nsFastLoadFile.cpp
@@ -897,7 +897,11 @@ nsFastLoadFileReader::Open()
         return NS_ERROR_FAILURE;
 
 #if defined(XP_UNIX)
+#ifndef __QNXNTO__
     madvise((char *)mFileData, mFileLen, MADV_WILLNEED);
+#else
+    posix_madvise((char *)mFileData, mFileLen, POSIX_MADV_WILLNEED);
+#endif
 #endif
 
     rv = ReadHeader(&mHeader);
