# $NetBSD: Makefile,v 1.4 2006/02/05 23:10:55 joerg Exp $
#

DISTNAME=		logfinder-0.1
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://www.eff.org/osp/

MAINTAINER=		jschauma@NetBSD.org
HOMEPAGE=		http://www.eff.org/osp/
COMMENT=		Eliminate Unwanted Logging of Personal Data

DEPENDS+=		lsof>=4.72:../../sysutils/lsof

NO_BUILD=		YES

PYTHON_PATCH_SCRIPTS+=	${WRKSRC}/logfinder.py
INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/logfinder.py ${PREFIX}/sbin/

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
