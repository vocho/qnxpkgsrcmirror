# $NetBSD: Makefile,v 1.33 2007/08/16 22:59:08 joerg Exp $

PKGNAME=	${DISTNAME:S/-/-client-/}
COMMENT=	Freeciv client

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	freeciv-share>=${FC_VERS}:../../games/freeciv-share
DEPENDS+=	freeciv-sounds>=3.0:../../games/freeciv-sounds

CONFLICTS=	freeciv-client-gtk<=1.11.4

USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--disable-make-data
CONFIGURE_ARGS+=	--disable-server

.include "../../games/freeciv-share/Makefile.common"

.include "options.mk"

.include "../../audio/esound/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
