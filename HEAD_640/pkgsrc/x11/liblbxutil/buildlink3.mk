# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/11/14 15:27:49 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBLBXUTIL_BUILDLINK3_MK:=	${LIBLBXUTIL_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	liblbxutil
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nliblbxutil}
BUILDLINK_PACKAGES+=	liblbxutil
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}liblbxutil

.if ${LIBLBXUTIL_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.liblbxutil+=	liblbxutil>=1.0.0
BUILDLINK_PKGSRCDIR.liblbxutil?=	../../x11/liblbxutil
.endif	# LIBLBXUTIL_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
