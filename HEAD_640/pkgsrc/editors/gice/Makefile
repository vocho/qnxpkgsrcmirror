# $NetBSD: Makefile,v 1.29 2008/03/03 18:25:52 jlam Exp $
#

DISTNAME=		gice-0.6.2
PKGREVISION=		3
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gice/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gice.sourceforge.net/
COMMENT=		Powerful C text editor with advanced features

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/gice
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		YES

BUILD_TARGET=		gice
INSTALLATION_DIRS=	bin

.include "../../x11/gtk2/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gice ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
