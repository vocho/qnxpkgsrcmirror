$NetBSD$

--- ipc/chromium/chromium-config.mk.orig	2013-04-10 03:01:45.000000000 +0000
+++ ipc/chromium/chromium-config.mk
@@ -105,6 +105,14 @@ DEFINES += \
   $(NULL)
 
 else # } {
+ifeq ($(OS_ARCH),QNX) # {
+
+OS_QNX = 1
+DEFINES += \
+  -DOS_QNX=1 \
+ $(NULL)
+
+else # } {
 
 OS_LINUX = 1
 DEFINES += \
@@ -120,4 +128,5 @@ endif # }
 endif # }
 endif # }
 endif # }
+endif # }
 
