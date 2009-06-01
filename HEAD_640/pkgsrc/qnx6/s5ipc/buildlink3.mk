# $NetBSD$
# XXX
# XXX This file was created automatically using createbuildlink-3.13.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.s5ipc?=	build

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
S5IPC_BUILDLINK3_MK:=	${S5IPC_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	s5ipc
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ns5ipc}
BUILDLINK_PACKAGES+=	s5ipc
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}s5ipc

.if ${S5IPC_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.s5ipc+=	s5ipc>=0.1
BUILDLINK_PKGSRCDIR.s5ipc?=	../../qnx6/s5ipc
.endif	# S5IPC_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
