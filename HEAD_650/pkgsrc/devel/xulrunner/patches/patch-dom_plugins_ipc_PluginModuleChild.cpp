$NetBSD$

--- dom/plugins/ipc/PluginModuleChild.cpp.orig	2013-04-10 03:01:33.000000000 +0000
+++ dom/plugins/ipc/PluginModuleChild.cpp
@@ -201,7 +201,7 @@ PluginModuleChild::Init(const std::strin
 
     // TODO: use PluginPRLibrary here
 
-#if defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_QNX)
     mShutdownFunc =
         (NP_PLUGINSHUTDOWN) PR_FindFunctionSymbol(mLibrary, "NP_Shutdown");
 
@@ -1828,7 +1828,7 @@ PluginModuleChild::AnswerNP_GetEntryPoin
     PLUGIN_LOG_DEBUG_METHOD;
     AssertPluginThread();
 
-#if defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_QNX)
     return true;
 #elif defined(OS_WIN) || defined(OS_MACOSX)
     *_retval = mGetEntryPointsFunc(&mFunctions);
@@ -1857,7 +1857,7 @@ PluginModuleChild::AnswerNP_Initialize(c
     SendBackUpXResources(FileDescriptor(xSocketFd));
 #endif
 
-#if defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_QNX)
     *_retval = mInitializeFunc(&sBrowserFuncs, &mFunctions);
     return true;
 #elif defined(OS_WIN) || defined(OS_MACOSX)
