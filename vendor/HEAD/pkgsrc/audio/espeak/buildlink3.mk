# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/07/17 19:18:44 drochner Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ESPEAK_BUILDLINK3_MK:=	${ESPEAK_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	espeak
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nespeak}
BUILDLINK_PACKAGES+=	espeak
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}espeak

.if ${ESPEAK_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.espeak+=	espeak>=1.26
BUILDLINK_PKGSRCDIR.espeak?=	../../audio/espeak
.endif	# ESPEAK_BUILDLINK3_MK

.include "../../audio/portaudio/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
