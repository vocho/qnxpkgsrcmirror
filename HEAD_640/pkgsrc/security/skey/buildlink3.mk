# $NetBSD: buildlink3.mk,v 1.8 2009/01/20 14:48:56 obache Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SKEY_BUILDLINK3_MK:=	${SKEY_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	skey
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nskey}
BUILDLINK_PACKAGES+=	skey
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}skey

.if !empty(SKEY_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.skey+=	skey>=1.1.5
BUILDLINK_ABI_DEPENDS.skey?=	skey>=1.1.5nb2
BUILDLINK_PKGSRCDIR.skey?=	../../security/skey
BUILDLINK_DEPMETHOD.skey?=	build
.endif	# SKEY_BUILDLINK3_MK

.include "../../mk/bsd.fast.prefs.mk"

# PR#40434
.if ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=	l:skey:skey:md5
.endif

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
