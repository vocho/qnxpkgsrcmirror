$NetBSD$

--- src/misc.C.orig	2012-01-02 03:57:35.000000000 +0000
+++ src/misc.C
@@ -170,7 +170,7 @@ rxvt_utf8towcs (const char *str, int len
 const char *
 rxvt_basename (const char *str) NOTHROW
 {
-  const char *base = strrchr (str, '/');
+  const char *base = (char *)strrchr (str, '/');
 
   return base ? base + 1 : str;
 }
