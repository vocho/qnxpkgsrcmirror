$NetBSD$

--- ipc/chromium/src/base/trace_event.h.orig	2011-08-11 21:41:01.000000000 +0000
+++ ipc/chromium/src/base/trace_event.h
@@ -22,6 +22,7 @@
 #endif
 
 #include <string>
+#include <stdio.h>
 
 #include "base/lock.h"
 #include "base/scoped_ptr.h"
