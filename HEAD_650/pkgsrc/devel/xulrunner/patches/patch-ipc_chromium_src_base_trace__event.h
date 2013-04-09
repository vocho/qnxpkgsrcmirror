$NetBSD$

--- ipc/chromium/src/base/trace_event.h.orig	2012-11-19 15:42:29.000000000 +0000
+++ ipc/chromium/src/base/trace_event.h
@@ -22,6 +22,7 @@
 #endif
 
 #include <string>
+#include <stdio.h>
 
 #include "base/lock.h"
 #include "base/scoped_ptr.h"
