$NetBSD$

--- media/libsydneyaudio/include/sydney_audio.h.orig	2012-11-19 15:43:03.000000000 +0000
+++ media/libsydneyaudio/include/sydney_audio.h
@@ -59,6 +59,12 @@ async-signal safe.
 #   endif
 #elif defined(AIX)
 #	define SA_BIG_ENDIAN 1
+#elif defined(__QNXNTO__)
+#   if defined(__BIGENDIAN__)
+#       define SA_BIG_ENDIAN 1
+#   else
+#       define SA_LITTLE_ENDIAN 1
+#   endif
 #else
 #    error "Cannot determine byte order!"
 #endif
