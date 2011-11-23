$NetBSD$

--- ipc/glue/GeckoChildProcessHost.cpp.orig	2011-08-11 21:41:01.000000000 +0000
+++ ipc/glue/GeckoChildProcessHost.cpp
@@ -270,7 +270,7 @@ void GeckoChildProcessHost::InitWindowsG
 #endif
 
 bool
-GeckoChildProcessHost::SyncLaunch(std::vector<std::string> aExtraOpts, int aTimeoutMs, base::ProcessArchitecture arch)
+GeckoChildProcessHost::SyncLaunch(std::vector<std::string> aExtraOpts, int32 aTimeoutMs, base::ProcessArchitecture arch)
 {
 #ifdef XP_WIN
   InitWindowsGroupID();
