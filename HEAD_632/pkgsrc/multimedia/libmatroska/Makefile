# $NetBSD: Makefile,v 1.22 2007/11/14 18:27:48 drochner Exp $
#

DISTNAME=	libmatroska-0.8.1
CATEGORIES=	multimedia devel
MASTER_SITES=	http://dl.matroska.org/downloads/libmatroska/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.matroska.org/
COMMENT=	Extensible open standard Audio/Video container format

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	gmake
USE_LANGUAGES=	c++
USE_LIBTOOL=	yes

NO_CONFIGURE=	yes
MAKEFLAGS+=	prefix=${PREFIX:Q}
MAKE_ENV+=	CXXFLAGS=${CXXFLAGS:M*:Q} RANLIB=${RANLIB:Q}
BUILD_DIRS=	make/linux
BUILD_TARGET=	sharedlib
INSTALL_TARGET=	install_headers install_sharedlib
TEST_TARGET=	test

# needed for libtoolization
BUILDLINK_API_DEPENDS.libebml+=	libebml>=0.7.7nb1
.include "../../devel/libebml/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
