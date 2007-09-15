# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/11/03 17:50:36 joerg Exp $

BUILDLINK_DEPMETHOD.xcmiscproto?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XCMISCPROTO_BUILDLINK3_MK:=	${XCMISCPROTO_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xcmiscproto
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxcmiscproto}
BUILDLINK_PACKAGES+=	xcmiscproto
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xcmiscproto

.if ${XCMISCPROTO_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xcmiscproto+=	xcmiscproto>=1.1
BUILDLINK_PKGSRCDIR.xcmiscproto?=	../../x11/xcmiscproto
.endif	# XCMISCPROTO_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
