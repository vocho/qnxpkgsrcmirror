$NetBSD$

--- ipc/chromium/src/base/debug_util_posix.cc.orig	2013-04-10 03:01:45.000000000 +0000
+++ ipc/chromium/src/base/debug_util_posix.cc
@@ -142,7 +142,25 @@ bool DebugUtil::BeingDebugged() {
   return pid_index < status.size() && status[pid_index] != '0';
 }
 
-#endif  // OS_LINUX
+#elif defined(OS_QNX)
+bool DebugUtil::BeingDebugged() {
+	int fd, rc;
+
+	/*
+	 * Only one O_RDWR is allowed at any point in time.
+	 * If we get EBUSY, assume it's the debugger.
+	 */
+	rc = false;
+	if ((fd = open("/proc/self/as", O_RDWR)) == -1) {
+		if (errno == EBUSY)
+			rc = true;
+	} else {
+		close(fd);
+	}
+	return rc;
+}
+
+#endif
 
 // static
 void DebugUtil::BreakDebugger() {
