# $NetBSD: Makefile,v 1.14 2009/06/29 17:10:27 joerg Exp $
#

DISTNAME=	qce-ga-0.40d
PKGNAME=	qcamview-0.4
PKGREVISION=	3
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qce-ga/}

PATCH_SITES=	http://www.medias.ne.jp/~takam/bsd/
PATCHFILES=	qce-ga-bsd-0.04.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	hamajima@NetBSD.org
HOMEPAGE=	http://www.medias.ne.jp/~takam/bsd/NetBSD.html#qcam
COMMENT=	Logitech Quickcam Express USB Utilities

INSTALLATION_DIRS=	${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

MAKE_ENV+=	${BSD_MAKE_ENV}

do-build:
	for f in qcamshot qcamview ; do				\
		cd ${WRKSRC} && ${SETENV} ${MAKE_ENV}		\
		NOGCCERROR=					\
		${MAKE_PROGRAM} -f ${MAKE_FILE}.$$f ;		\
	done

do-install:
	for f in qcamshot qcamview ; do				\
		cd ${WRKSRC} && ${SETENV} ${MAKE_ENV}		\
		${MAKE_PROGRAM} -f ${MAKE_FILE}.$$f install ;	\
	done

.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
