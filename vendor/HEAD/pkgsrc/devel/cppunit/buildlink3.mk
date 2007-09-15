# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:10:42 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
CPPUNIT_BUILDLINK3_MK:=	${CPPUNIT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	cppunit
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ncppunit}
BUILDLINK_PACKAGES+=	cppunit
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}cppunit

.if !empty(CPPUNIT_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.cppunit+=	cppunit>=1.10.2
BUILDLINK_ABI_DEPENDS.cppunit?=	cppunit>=1.10.2nb5
BUILDLINK_PKGSRCDIR.cppunit?=	../../devel/cppunit
BUILDLINK_CPPFLAGS.cppunit+=	-I${BUILDLINK_PREFIX.cppunit}/include/cppunit
.endif	# CPPUNIT_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
