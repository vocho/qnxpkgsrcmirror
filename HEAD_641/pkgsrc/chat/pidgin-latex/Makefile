# $NetBSD: Makefile,v 1.4 2009/08/11 12:17:20 drochner Exp $

VERSION=	1.2.1
PKGREVISION=	2
DISTNAME=	pidgin-latex-${VERSION}
EXTRACT_SUFX=	.tar.bz2
CATEGORIES=	chat print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pidgin-latex/}
WRKSRC=		${WRKDIR}/pidgin-latex

MAINTAINER=	smb@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/pidgin-latex/
COMMENT=	Plugin for pidgin to render LaTeX as images

USE_TOOLS+=	gmake
USE_TOOLS+=	pkg-config

#PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	share/doc/pidgin-latex

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/pidgin-latex/

DEPENDS+= ImageMagick-[0-9]*:../../graphics/ImageMagick

.include "../../chat/pidgin/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
