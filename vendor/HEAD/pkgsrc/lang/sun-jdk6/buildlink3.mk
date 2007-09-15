# $NetBSD: buildlink3.mk,v 1.2 2007/05/25 02:04:15 rh Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SUN_JDK6_BUILDLINK3_MK:=	${SUN_JDK6_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	sun-jdk6
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsun-jdk6}
BUILDLINK_PACKAGES+=	sun-jdk6
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}sun-jdk6

.if !empty(SUN_JDK6_BUILDLINK3_MK:M+)

BUILDLINK_API_DEPENDS.sun-jdk6+=	sun-jdk6-[0-9]*
BUILDLINK_ABI_DEPENDS.sun-jdk6?=	sun-jdk6>=6.0.1
BUILDLINK_PKGSRCDIR.sun-jdk6?=	../../lang/sun-jdk6
BUILDLINK_DEPMETHOD.sun-jdk6?= build

BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_JAVA_PREFIX.sun-jre6}

BUILDLINK_CPPFLAGS.sun-jdk6=						\
	-I${BUILDLINK_JAVA_PREFIX.sun-jre6}/include			\
	-I${BUILDLINK_JAVA_PREFIX.sun-jre6}/include/linux

.include "../../lang/sun-jre6/buildlink3.mk"

.endif	# SUN_JDK6_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
