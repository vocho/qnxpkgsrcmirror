# $NetBSD: Makefile,v 1.9 2009/02/09 18:51:19 joerg Exp $
#

DISTNAME=		pyproj-1.8.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/pyproj/proj/}
CATEGORIES=		geography
MASTER_SITES=		http://pyproj.googlecode.com/files/

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://code.google.com/p/pyproj/
COMMENT=		Python wrapper for proj

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED=	25 24
PYDISTUTILSPKG=			true

INSTALLATION_DIRS=	share/doc/${PKGNAME}

post-install:
	${INSTALL} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/${PKGNAME}

.include "../../lang/python/extension.mk"

.include "../../misc/proj/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
