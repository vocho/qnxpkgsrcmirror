$NetBSD$

--- ipc/chromium/src/base/process_util_bsd.cc.orig	2013-04-10 03:01:46.000000000 +0000
+++ ipc/chromium/src/base/process_util_bsd.cc
@@ -4,6 +4,9 @@
 
 // derived from process_util_linux.cc and process_util_mac.cc
 
+#ifdef __QNXNTO__
+#define __STDC_CONSTANT_MACROS
+#endif
 #include "base/process_util.h"
 
 #include <sys/param.h>
@@ -302,6 +305,7 @@ bool LaunchApp(const CommandLine& cl,
 NamedProcessIterator::NamedProcessIterator(const std::wstring& executable_name,
                                            const ProcessFilter* filter)
 {
+#if !defined(OS_QNX)
   int numEntries;
   kvm_t *kvm;
   std::string exe(WideToASCII(executable_name));
@@ -349,6 +353,9 @@ NamedProcessIterator::NamedProcessIterat
   }
   nextEntry = 0;
   kvm_close(kvm);
+#else
+  nextEntry = 0;
+#endif
 }
 
 NamedProcessIterator::~NamedProcessIterator() {
