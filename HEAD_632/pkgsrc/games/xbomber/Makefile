# $NetBSD: Makefile,v 1.15 2007/02/02 18:22:58 joerg Exp $
#

DISTNAME=	xbomber.0.8
PKGNAME=	xbomber-0.8
PKGREVISION=	2
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/xbomber/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.newbreedsoftware.com/xbomber/
COMMENT=	Colorful game where you blow other people/robots up

WRKSRC=		${WRKDIR}/xbomber
MAKE_FILE=	makefile

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xbomber
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/xbomber

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
