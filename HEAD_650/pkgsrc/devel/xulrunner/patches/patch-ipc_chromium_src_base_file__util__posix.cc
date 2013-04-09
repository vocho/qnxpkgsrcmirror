$NetBSD: patch-ipc_chromium_src_base_file__util__posix.cc,v 1.5 2012/08/28 23:27:10 ryoon Exp $

--- ipc/chromium/src/base/file_util_posix.cc.orig	2012-11-19 15:42:29.000000000 +0000
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
 #include <sys/stat.h>
 #include <sys/types.h>
@@ -33,7 +38,7 @@
 #include "base/time.h"
 
 // FreeBSD/OpenBSD lacks stat64, but its stat handles files >2GB just fine
-#if defined(OS_FREEBSD) || defined(OS_OPENBSD)
+#ifndef HAVE_STAT64
 #define stat64 stat
 #endif
 
