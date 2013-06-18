$NetBSD$

--- dom/plugins/ipc/PluginModuleChild.h.orig	2013-04-10 03:01:33.000000000 +0000
+++ dom/plugins/ipc/PluginModuleChild.h
@@ -325,7 +325,7 @@ private:
 
     // we get this from the plugin
     NP_PLUGINSHUTDOWN mShutdownFunc;
-#if defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_QNX)
     NP_PLUGINUNIXINIT mInitializeFunc;
 #elif defined(OS_WIN) || defined(OS_MACOSX)
     NP_PLUGININIT mInitializeFunc;
