$NetBSD: patch-ipc_chromium_src_base_file__util__posix.cc,v 1.1 2011/07/11 12:46:14 tnn Exp $

--- ipc/chromium/src/base/file_util_posix.cc.orig	2011-08-11 21:41:01.000000000 +0000
+++ ipc/chromium/src/base/file_util_posix.cc
@@ -4,6 +4,9 @@
 
 #include "base/file_util.h"
 
+#ifdef OS_QNX
+#define ANDROID /* fts isn't posix */
+#endif
 #include <dirent.h>
 #include <errno.h>
 #include <fcntl.h>
@@ -14,7 +17,11 @@
 #include <libgen.h>
 #include <stdio.h>
 #include <string.h>
+#ifndef OS_QNX
 #include <sys/errno.h>
+#else
+#include <errno.h> /* posix */
+#endif
 #include <sys/mman.h>
 #include <sys/stat.h>
 #include <sys/types.h>
@@ -30,6 +37,9 @@
 #include "base/string_util.h"
 #include "base/time.h"
 
+#ifndef __linux__
+#define stat64 stat
+#endif
 namespace file_util {
 
 #if defined(GOOGLE_CHROME_BUILD)
