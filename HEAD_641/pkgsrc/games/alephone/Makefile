# $NetBSD: Makefile,v 1.7 2008/11/08 21:13:27 bjs Exp $
#

DISTNAME=	AlephOne-20071103
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	5
CATEGORIES=	games
MASTER_SITES+=	${MASTER_SITE_SOURCEFORGE:=marathon/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://marathon.sourceforge.net/
COMMENT=	Classic 2.5D FPS game engine, updated to use SDL

GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c c++
INSTALLATION_DIRS=	share/doc/AlephOne

CONFIGURE_ARGS=	--disable-speex

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/AlephOne/

.include "../../audio/SDL_sound/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
