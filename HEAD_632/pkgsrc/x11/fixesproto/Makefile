# $NetBSD: Makefile,v 1.5 2006/11/03 17:09:27 joerg Exp $
#

DISTNAME=		fixesproto-4.0
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Fixes extension headers from X.org

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		fixesext-[0-9]*

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/fixesproto.pc.in
USE_LANGUAGES=		# none, not even C

.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
