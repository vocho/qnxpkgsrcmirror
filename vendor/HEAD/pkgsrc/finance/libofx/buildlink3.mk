# $NetBSD: buildlink3.mk,v 1.7 2006/09/03 13:02:17 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBOFX_BUILDLINK3_MK:=	${LIBOFX_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libofx
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibofx}
BUILDLINK_PACKAGES+=	libofx
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libofx

.if !empty(LIBOFX_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libofx+=	libofx>=0.8.0
BUILDLINK_PKGSRCDIR.libofx?=	../../finance/libofx
BUILDLINK_INCDIRS.libofx+=	include/libofx
.endif	# LIBOFX_BUILDLINK3_MK

.include "../../textproc/opensp/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
