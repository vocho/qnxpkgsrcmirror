# $NetBSD: Makefile,v 1.34 2007/11/25 23:20:50 wiz Exp $

DISTNAME=		devilspie-0.22
CATEGORIES=		x11
MASTER_SITES=		http://www.burtonini.com/computing/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.burtonini.com/blog/computers/devilspie/
COMMENT=		Window-matching utility to customize window behavior

BUILD_DEPENDS+=		libxslt>=1.0:../../textproc/libxslt

USE_TOOLS+=		intltool msgfmt pkg-config
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
TEST_TARGET=		check

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/devilspie
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/devilspie/

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.9.1
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
