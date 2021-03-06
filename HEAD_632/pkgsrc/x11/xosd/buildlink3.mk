# $NetBSD: buildlink3.mk,v 1.9 2006/07/08 23:11:17 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XOSD_BUILDLINK3_MK:=	${XOSD_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xosd
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxosd}
BUILDLINK_PACKAGES+=	xosd
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xosd

.if !empty(XOSD_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.xosd+=	xosd>=2.2.12
BUILDLINK_ABI_DEPENDS.xosd+=	xosd>=2.2.12nb2
BUILDLINK_PKGSRCDIR.xosd?=	../../x11/xosd
.endif	# XOSD_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
