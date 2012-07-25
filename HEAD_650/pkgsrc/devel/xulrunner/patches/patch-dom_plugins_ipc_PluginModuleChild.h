$NetBSD: patch-dom_plugins_ipc_PluginModuleChild.h,v 1.1 2012/03/06 12:34:09 ryoon Exp $

--- dom/plugins/ipc/PluginModuleChild.h.orig	2012-03-13 01:36:45.000000000 +0000
+++ dom/plugins/ipc/PluginModuleChild.h
@@ -360,7 +360,7 @@ private:
 
     // we get this from the plugin
     NP_PLUGINSHUTDOWN mShutdownFunc;
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_QNX)
     NP_PLUGINUNIXINIT mInitializeFunc;
 #elif defined(OS_WIN) || defined(OS_MACOSX)
     NP_PLUGININIT mInitializeFunc;
