# $NetBSD: Makefile,v 1.2 2008/06/01 15:32:31 tnn Exp $
#

DISTNAME=	libcompizconfig-0.6.0
CATEGORIES=	devel gnome
MASTER_SITES=	http://releases.compiz-fusion.org/0.6.0/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.compiz-fusion.org/
COMMENT=	Configuration backend for compiz

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config perl intltool

PKG_SYSCONFSUBDIR?=	compizconfig
EGDIR=		${PREFIX}/share/examples/compizconfig
CONF_FILES+=	${EGDIR}/config ${PKG_SYSCONFDIR}/config

PKGCONFIG_OVERRIDE=	libcompizconfig.pc.in

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wm/compiz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
