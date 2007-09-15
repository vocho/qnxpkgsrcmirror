# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:11:04 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OPENH323_BUILDLINK3_MK:=	${OPENH323_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	openh323
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nopenh323}
BUILDLINK_PACKAGES+=	openh323
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}openh323

.if !empty(OPENH323_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.openh323+=	openh323>=1.15.1
BUILDLINK_ABI_DEPENDS.openh323+=	openh323>=1.15.2nb1
BUILDLINK_PKGSRCDIR.openh323?=	../../net/openh323
.endif	# OPENH323_BUILDLINK3_MK

.include "../../devel/pwlib/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
