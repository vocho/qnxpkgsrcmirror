# $NetBSD: Makefile,v 1.16 2008/06/20 01:09:18 joerg Exp $
#

DISTNAME=		tme-0.6
PKGREVISION=		0
CATEGORIES=		emulators
MASTER_SITES=		http://csail.mit.edu/~fredette/tme/

MAINTAINER=		skrll@NetBSD.org
# Please do not assign PR's for this package to skrll.
# Instead, assign them to the package author, fredette.

PKG_DESTDIR_SUPPORT=	user-destdir

HOMEPAGE=		http://csail.mit.edu/~fredette/tme/
COMMENT=		The Machine Emulator

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl:run

CONFIGURE_ARGS+=	--disable-debug

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/libltdl/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
