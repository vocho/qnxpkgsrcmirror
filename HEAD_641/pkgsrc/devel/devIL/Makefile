# $NetBSD: Makefile,v 1.19 2008/06/12 02:14:22 joerg Exp $
#

DISTNAME=	DevIL-1.6.6
PKGNAME=	${DISTNAME:S/D/d/}
PKGREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openil/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://openil.sourceforge.net/
COMMENT=	Developer's Image Library

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/DevIL
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--disable-lcms

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
