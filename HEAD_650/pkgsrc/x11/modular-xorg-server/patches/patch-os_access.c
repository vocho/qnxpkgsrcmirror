$NetBSD$

--- os/access.c.orig	2009-10-12 02:52:40.000000000 +0000
+++ os/access.c
@@ -491,7 +491,7 @@ in6_fillscopeid(struct sockaddr_in6 *sin
 #if defined(__KAME__)
 	if (IN6_IS_ADDR_LINKLOCAL(&sin6->sin6_addr)) {
 		sin6->sin6_scope_id =
-			ntohs(*(u_int16_t *)&sin6->sin6_addr.s6_addr[2]);
+			ntohs(*(uint16_t *)&sin6->sin6_addr.s6_addr[2]);
 		sin6->sin6_addr.s6_addr[2] = sin6->sin6_addr.s6_addr[3] = 0;
 	}
 #endif
