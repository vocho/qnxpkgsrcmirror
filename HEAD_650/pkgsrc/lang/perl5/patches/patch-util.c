$NetBSD$

--- util.c.orig	2012-10-26 02:44:15.000000000 +0000
+++ util.c
@@ -2978,7 +2978,14 @@ Perl_atfork_unlock(void)
 #  ifdef MYMALLOC
     MUTEX_UNLOCK(&PL_malloc_mutex);
 #  endif
+#    ifndef __QNXNTO__
     OP_REFCNT_UNLOCK;
+#    else
+    if (pthread_mutex_init(&readdir_mutex, NULL) != EOK) {
+	    /* new proc that supports inheritence of sync objects */
+	    OP_REFCNT_UNLOCK;
+    }
+#    endif
 #endif
 }
 
