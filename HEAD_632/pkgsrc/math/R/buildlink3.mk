# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:10:58 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
R_BUILDLINK3_MK:=	${R_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	R
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NR}
BUILDLINK_PACKAGES+=	R
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}R

.if !empty(R_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.R+=	R>=1.7.0
BUILDLINK_ABI_DEPENDS.R?=	R>=2.2.1nb2
BUILDLINK_PKGSRCDIR.R?=	../../math/R
.endif	# R_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
