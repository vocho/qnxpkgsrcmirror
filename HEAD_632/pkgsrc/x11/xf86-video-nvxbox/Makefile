# $NetBSD: Makefile,v 1.1.1.1 2007/04/09 14:58:34 xtraeme Exp $
#

DISTNAME=	xf86-video-nvxbox-${VER}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_BACKUP}

MAINTAINER=	joerg@NetBSD.org
COMMENT=	Modular Xorg NVidia Xbox video driver

PKG_DESTDIR_SUPPORT=    user-destdir

VER=		20070409
WRKSRC=		${WRKDIR}/${DISTNAME:S/-${VER}//}

USE_LIBTOOL=    yes
GNU_CONFIGURE=  yes
USE_TOOLS+=     pkg-config

.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"
.include "../../x11/videoproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/glproto/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
