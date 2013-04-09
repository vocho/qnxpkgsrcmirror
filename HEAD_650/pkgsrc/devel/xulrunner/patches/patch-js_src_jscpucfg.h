$NetBSD: patch-js_src_jscpucfg.h,v 1.4 2012/08/28 23:27:10 ryoon Exp $


--- js/src/jscpucfg.h.orig	2012-11-19 15:42:33.000000000 +0000
+++ js/src/jscpucfg.h
@@ -44,6 +44,36 @@
 #  define IS_BIG_ENDIAN 1
 # endif
 
+#elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__MirBSD__) || defined(__DragonFly__)
+#include <sys/endian.h>
+
+#if defined(_BYTE_ORDER)
+#if _BYTE_ORDER == _LITTLE_ENDIAN
+#define IS_LITTLE_ENDIAN 1
+#undef  IS_BIG_ENDIAN
+#elif _BYTE_ORDER == _BIG_ENDIAN
+#undef  IS_LITTLE_ENDIAN
+#define IS_BIG_ENDIAN 1
+#endif
+#else /* !defined(_BYTE_ORDER) */
+#error "sys/endian.h does not define _BYTE_ORDER. Cannot determine endianness."
+#endif
+
+#elif defined(__QNXNTO__)
+#include <sys/param.h>
+
+#if defined(BYTE_ORDER)
+#if BYTE_ORDER == LITTLE_ENDIAN
+#define IS_LITTLE_ENDIAN 1
+#undef  IS_BIG_ENDIAN
+#elif BYTE_ORDER == BIG_ENDIAN
+#undef  IS_LITTLE_ENDIAN
+#define IS_BIG_ENDIAN 1
+#endif
+#else /* !defined(BYTE_ORDER) */
+#error "sys/param.h does not define BYTE_ORDER. Cannot determine endianness."
+#endif
+
 #elif defined(JS_HAVE_ENDIAN_H)
 # include <endian.h>
 
