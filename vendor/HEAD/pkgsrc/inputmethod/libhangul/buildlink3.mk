# $NetBSD: buildlink3.mk,v 1.2 2007/05/09 17:29:39 minskim Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBHANGUL_BUILDLINK3_MK:=	${LIBHANGUL_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libhangul
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibhangul}
BUILDLINK_PACKAGES+=	libhangul
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libhangul

.if ${LIBHANGUL_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libhangul+=	libhangul>=0.0.4
BUILDLINK_PKGSRCDIR.libhangul?=	../../inputmethod/libhangul
.endif	# LIBHANGUL_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
