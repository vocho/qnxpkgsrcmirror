# $NetBSD: buildlink3.mk,v 1.20 2013/02/06 23:20:53 jperkin Exp $

BUILDLINK_TREE+=	libtorrent

.if !defined(LIBTORRENT_BUILDLINK3_MK)
LIBTORRENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtorrent+=	libtorrent>=0.13.2
BUILDLINK_ABI_DEPENDS.libtorrent+=	libtorrent>=0.13.2nb2
BUILDLINK_PKGSRCDIR.libtorrent?=	../../net/libtorrent

.include "../../devel/libsigc++/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # LIBTORRENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtorrent
