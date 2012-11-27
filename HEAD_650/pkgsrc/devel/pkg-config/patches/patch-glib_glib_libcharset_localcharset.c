$NetBSD$

--- glib/glib/libcharset/localcharset.c.orig	2012-05-14 22:06:02.000000000 +0000
+++ glib/glib/libcharset/localcharset.c
@@ -361,6 +361,10 @@ _g_locale_charset_raw (void)
 	    locale = getenv ("LANG");
 	}
     }
+#ifdef __QNXNTO__ /* We need nl_langinfo() */
+    if (locale != NULL && strcmp(locale, "C") == 0)
+	locale = "ASCII";
+#endif
 
   /* On some old systems, one used to set locale = "iso8859_1". On others,
      you set it to "language_COUNTRY.charset". In any case, we resolve it
