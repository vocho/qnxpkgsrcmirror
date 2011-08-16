$NetBSD$

--- config/elf-dynstr-gc.c.orig	2011-04-14 05:28:22.000000000 +0000
+++ config/elf-dynstr-gc.c
@@ -53,7 +53,12 @@
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
 
