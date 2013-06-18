$NetBSD$

--- ipc/chromium/src/base/base_paths.h.orig	2013-04-10 03:01:45.000000000 +0000
+++ ipc/chromium/src/base/base_paths.h
@@ -13,7 +13,7 @@
 #include "base/base_paths_win.h"
 #elif defined(OS_MACOSX)
 #include "base/base_paths_mac.h"
-#elif defined(OS_LINUX) || defined(OS_BSD)
+#elif defined(OS_LINUX) || defined(OS_BSD) || defined(OS_QNX)
 #include "base/base_paths_linux.h"
 #endif
 #include "base/path_service.h"
