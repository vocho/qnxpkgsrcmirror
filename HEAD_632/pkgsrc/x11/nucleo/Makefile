# $NetBSD: Makefile,v 1.3 2007/08/12 14:26:41 joerg Exp $
#

DISTNAME=	nucleo-0.6
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://insitu.lri.fr/metisse/download/0.4.0-rc4/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://insitu.lri.fr/metisse/
COMMENT=	Toolkit to explore new uses of video and HCI techniques

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c c++
USE_LIBTOOL=	yes

REPLACE_PYTHON+=	docs/MacOSX/nBundle.in

.include "../../lang/python/application.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../net/mDNSResponder/buildlink3.mk"

.include "../../x11/libICE/buildlink3.mk"

BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libXt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
