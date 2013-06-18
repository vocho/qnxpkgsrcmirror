$NetBSD$

--- config/elf-dynstr-gc.c.orig	2013-04-10 03:01:22.000000000 +0000
+++ config/elf-dynstr-gc.c
@@ -21,7 +21,12 @@
 #include <sys/stat.h>
 #include <sys/mman.h>
 
+#ifndef __QNXNTO__
 #include <elf.h>
+#else
+#include <sys/elf.h>
+#include <sys/elf_dyn.h>
+#endif
 #include <glib.h>
 #include <string.h>
 
