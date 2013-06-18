$NetBSD$

--- ipc/chromium/src/base/file_util_posix.cc.orig	2013-04-10 03:01:45.000000000 +0000
+++ ipc/chromium/src/base/file_util_posix.cc
@@ -4,6 +4,9 @@
 
 #include "base/file_util.h"
 
+#ifdef OS_QNX
+#define ANDROID /* fts isn't posix */
+#endif
 #include <dirent.h>
 #include <errno.h>
 #include <fcntl.h>
@@ -14,7 +17,9 @@
 #include <libgen.h>
 #include <stdio.h>
 #include <string.h>
+#ifndef OS_QNX /* not posix. errno.h brough in above */
 #include <sys/errno.h>
+#endif
 #include <sys/mman.h>
 #define _DARWIN_USE_64_BIT_INODE // Use 64-bit inode data structures
 #include <sys/stat.h>
