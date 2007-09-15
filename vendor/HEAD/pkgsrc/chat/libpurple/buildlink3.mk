# $NetBSD: buildlink3.mk,v 1.3 2007/08/13 12:42:06 tnn Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBPURPLE_BUILDLINK3_MK:=	${LIBPURPLE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libpurple
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibpurple}
BUILDLINK_PACKAGES+=	libpurple
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libpurple

.if ${LIBPURPLE_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libpurple+=	libpurple>=2.1.0
BUILDLINK_PKGSRCDIR.libpurple?=	../../chat/libpurple
.endif	# LIBPURPLE_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
