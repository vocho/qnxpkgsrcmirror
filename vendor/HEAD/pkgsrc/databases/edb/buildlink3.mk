# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:10:39 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EDB_BUILDLINK3_MK:=	${EDB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	edb
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nedb}
BUILDLINK_PACKAGES+=	edb
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}edb

.if !empty(EDB_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.edb+=	edb>=1.0.3nb3
BUILDLINK_ABI_DEPENDS.edb+=	edb>=1.0.3nb5
BUILDLINK_PKGSRCDIR.edb?=	../../databases/edb
.endif	# EDB_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
