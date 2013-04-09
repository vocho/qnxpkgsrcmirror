$NetBSD$

--- toolkit/components/osfile/osfileutils.cpp.orig	2012-11-19 15:43:22.000000000 +0000
+++ toolkit/components/osfile/osfileutils.cpp
@@ -7,6 +7,9 @@
 #include "nsCOMPtr.h"
 #include "nsCRTGlue.h"
 
+#ifdef __QNXNTO__
+#include <errno.h> /* outside of namespace {} block below */
+#endif
 // Utilities for handling errors
 namespace {
 
