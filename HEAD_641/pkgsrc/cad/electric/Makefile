# $NetBSD: Makefile,v 1.18 2009/08/01 16:22:25 dholland Exp $
#

DISTNAME=	electric-7.00
PKGREVISION=	3
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GNU:=electric/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/electric/electric.html
COMMENT=	Electrical CAD system

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++

post-patch:
	${MV} ${WRKSRC}/src/include/config.h ${WRKSRC}/src/include/config.h.bak
	${SED}  -e 's;@prefix@;${PREFIX};g' \
		-e 's;@localbase@;${LOCALBASE};g' \
		< ${WRKSRC}/src/include/config.h.bak \
		> ${WRKSRC}/src/include/config.h

INSTALL_TARGET=	install install.html
INSTALLATION_DIRS=	bin

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
