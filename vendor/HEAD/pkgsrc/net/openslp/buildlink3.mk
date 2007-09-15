# $NetBSD: buildlink3.mk,v 1.11 2006/07/08 23:11:04 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OPENSLP_BUILDLINK3_MK:=	${OPENSLP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	openslp
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nopenslp}
BUILDLINK_PACKAGES+=	openslp
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}openslp

.if !empty(OPENSLP_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.openslp+=	openslp>=1.0.1
BUILDLINK_ABI_DEPENDS.openslp+=	openslp>=1.2.1
BUILDLINK_PKGSRCDIR.openslp?=	../../net/openslp
.endif	# OPENSLP_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
