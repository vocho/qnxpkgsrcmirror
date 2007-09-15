# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:59 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LTM_BUILDLINK3_MK:=	${LTM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ltm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nltm}
BUILDLINK_PACKAGES+=	ltm
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}ltm

.if !empty(LTM_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.ltm+=	ltm>=0.30
BUILDLINK_ABI_DEPENDS.ltm?=	ltm>=0.30nb1
BUILDLINK_PKGSRCDIR.ltm?=	../../math/ltm
BUILDLINK_DEPMETHOD.ltm?=	build
.endif	# LTM_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
