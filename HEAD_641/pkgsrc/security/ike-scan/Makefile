# $NetBSD: Makefile,v 1.12 2009/07/17 18:00:23 adrianp Exp $

DISTNAME=	ike-scan-1.9
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.nta-monitor.com/tools/ike-scan/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nta-monitor.com/tools/ike-scan/
COMMENT=	Fingerprinting IKE implementation

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-openssl

SUBST_CLASSES+=		man
SUBST_STAGE.man=	post-patch
SUBST_FILES.man=	ike-scan.1
SUBST_SED.man=		-e "s|/usr/local|${PREFIX}|g"
SUBST_MESSAGE.man=	Fixing man pages.

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ike-scan
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ike-scan/README

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
