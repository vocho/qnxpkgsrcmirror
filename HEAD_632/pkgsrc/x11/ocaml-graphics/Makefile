# $NetBSD: Makefile,v 1.7 2007/01/30 20:56:13 joerg Exp $

.include "../../lang/ocaml/Makefile.common"

PKGNAME=		${DISTNAME:S/ocaml/ocaml-graphics/}
PKGREVISION=		2

COMMENT+=		(graphics library)

CONFIGURE_ARGS+=	-x11include ${X11BASE}/include
CONFIGURE_ARGS+=	-x11lib ${X11BASE}/lib
CONFIGURE_ARGS+=	-no-tk

BUILD_DIRS=		${WRKSRC}/otherlibs/graph
BUILD_TARGET=		all
INSTALL_TARGET=		install
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc")
BUILD_TARGET+=		allopt
INSTALL_TARGET+=	installopt
PLIST_SUBST+=		OPT=
.else
PLIST_SUBST+=		OPT='@comment '
.endif

PLIST_SRC=	${WRKDIR}/.PLIST_SRC

.if ${OPSYS} == "Darwin"
PLIST_SRC+=	${PKGDIR}/PLIST.stub
.endif

BUILDLINK_DEPMETHOD.ocaml=	full

SUBST_CLASSES+=		depend
SUBST_STAGE.depend=	post-patch
SUBST_FILES.depend=	otherlibs/graph/.depend
SUBST_SED.depend=	-e 's,/usr/X11R6,${X11BASE},g'
SUBST_MESSAGE.depend=	Fixing .depend in otherlibs/graph.

post-build:
	@${CP} ${PKGDIR}/PLIST ${WRKDIR}/.PLIST_SRC

.include "../../lang/ocaml/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
