# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:48 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SYSEXITS_BUILDLINK3_MK:=	${SYSEXITS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	sysexits
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsysexits}
BUILDLINK_PACKAGES+=	sysexits
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}sysexits

.if !empty(SYSEXITS_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.sysexits+=	sysexits>=1.1
BUILDLINK_DEPMETHOD.sysexits?=	build
BUILDLINK_PKGSRCDIR.sysexits?=	../../devel/sysexits
.endif	# SYSEXITS_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
