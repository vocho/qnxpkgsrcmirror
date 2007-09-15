# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/08/03 21:30:59 tnn Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBSETENV_BUILDLINK3_MK:=	${LIBSETENV_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libsetenv
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibsetenv}
BUILDLINK_PACKAGES+=	libsetenv
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libsetenv

.if ${LIBSETENV_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libsetenv+=	libsetenv>=0.1
BUILDLINK_PKGSRCDIR.libsetenv?=		../../devel/libsetenv
.endif	# LIBSETENV_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
