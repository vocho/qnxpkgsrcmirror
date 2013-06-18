$NetBSD: patch-os_utils.c,v 1.1 2012/12/15 09:26:07 is Exp $

--- os/utils.c.orig	2013-05-03 17:12:29.000000000 +0000
+++ os/utils.c
@@ -319,7 +319,7 @@ LockServer(void)
     FatalError("Could not create lock file in %s\n", tmp);
   (void) sprintf(pid_str, "%10ld\n", (long)getpid());
   (void) write(lfd, pid_str, 11);
-  (void) chmod(tmp, 0444);
+  (void) fchmod(lfd, 0444);
   (void) close(lfd);
 
   /*
@@ -340,7 +340,11 @@ LockServer(void)
       /*
        * Read the pid from the existing file
        */
-      lfd = open(LockFile, O_RDONLY);
+      int oflag = O_RDONLY;
+#ifdef O_NOFOLLOW
+      oflag |= O_NOFOLLOW;
+#endif
+      lfd = open(LockFile, oflag);
       if (lfd < 0) {
         unlink(tmp);
         FatalError("Can't read lock file %s\n", LockFile);
