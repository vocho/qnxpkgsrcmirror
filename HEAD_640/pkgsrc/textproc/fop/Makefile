# $NetBSD: Makefile,v 1.28 2008/05/25 21:42:22 joerg Exp $
#
# Note: we currently use the pre-built (-bin) distribution of FOP,
# because although FOP runs fine under JDK 1.1, JDK 1.2 or greater is
# required to build it.
#
# Note: please do NOT update this package to a more recent version of FOP --
# this is the most recent version which works with cocoon.  If you need a
# newer version, let me know, and I will import the latest version as
# fop-current -- jwise@NetBSD.org
#

DISTNAME=	fop-0_15_0-forBeginners
PKGNAME=	fop-0.15.0
PKGREVISION=	2
CATEGORIES=	textproc www
MASTER_SITES=	http://xmlgraphics.apache.org/dist/fop/recent/
EXTRACT_SUFX=	.zip

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://xmlgraphics.apache.org/fop/
COMMENT=	The Apache Project's XSL Formatting Objects implementation

WRKSRC=		${WRKDIR}
USE_JAVA=	run
USE_TOOLS+=	pax
NO_CONFIGURE=	yes
NO_BUILD=	yes
INSTALLATION_DIRS=	lib/java share/doc/java/fop

.include "../../mk/bsd.prefs.mk"

post-extract:
.if ${OPSYS:M*BSD}
	find -d ${WRKSRC}/docs -name cvs -exec ${RM} -r '{}' \;
.else
	find ${WRKSRC}/docs -depth -name cvs -exec ${RM} -r '{}' \;
.endif
	cd ${WRKSRC} && chmod -R go-w .

do-install:
	${INSTALL_DATA} ${WRKSRC}/build/fop.jar ${PREFIX}/lib/java/fop.jar
	${INSTALL_DATA} ${WRKSRC}/lib/w3c.jar ${PREFIX}/lib/java/fop-w3c.jar
	cd ${WRKSRC}/docs && pax -rw . ${PREFIX}/share/doc/java/fop

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
