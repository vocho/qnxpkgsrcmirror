$NetBSD: patch-ipc_glue_GeckoChildProcessHost.cpp,v 1.6 2013/01/10 15:01:31 ryoon Exp $

--- ipc/glue/GeckoChildProcessHost.cpp.orig	2013-04-10 03:01:47.000000000 +0000
+++ ipc/glue/GeckoChildProcessHost.cpp
@@ -4,7 +4,13 @@
  * License, v. 2.0. If a copy of the MPL was not distributed with this
  * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
+#if defined(__NetBSD__)
+_Pragma("GCC visibility push(default)")
+#endif
 #include "GeckoChildProcessHost.h"
+#if defined(__NetBSD__)
+_Pragma("GCC visibility pop")
+#endif
 
 #include "base/command_line.h"
 #include "base/path_service.h"
@@ -486,7 +492,7 @@ GeckoChildProcessHost::PerformAsyncLaunc
   // and passing wstrings from one config to the other is unsafe.  So
   // we split the logic here.
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD) || defined(OS_QNX)
   base::environment_map newEnvVars;
   ChildPrivileges privs = mPrivileges;
   if (privs == base::PRIVILEGES_DEFAULT) {
@@ -506,7 +512,7 @@ GeckoChildProcessHost::PerformAsyncLaunc
       if (NS_SUCCEEDED(rv)) {
         nsCString path;
         greDir->GetNativePath(path);
-# if defined(OS_LINUX) || defined(OS_BSD)
+# if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_QNX)
 #  if defined(MOZ_WIDGET_ANDROID)
         path += "/lib";
 #  endif  // MOZ_WIDGET_ANDROID
@@ -629,7 +635,7 @@ GeckoChildProcessHost::PerformAsyncLaunc
   childArgv.push_back(pidstring);
 
 #if defined(MOZ_CRASHREPORTER)
-#  if defined(OS_LINUX) || defined(OS_BSD)
+#  if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_QNX)
   int childCrashFd, childCrashRemapFd;
   if (!CrashReporter::CreateNotificationPipeForChild(
         &childCrashFd, &childCrashRemapFd))
@@ -666,7 +672,7 @@ GeckoChildProcessHost::PerformAsyncLaunc
 #endif
 
   base::LaunchApp(childArgv, mFileMap,
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD) || defined(OS_QNX)
                   newEnvVars, privs,
 #endif
                   false, &process, arch);
