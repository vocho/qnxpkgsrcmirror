# $NetBSD: Makefile,v 1.23 2009/08/05 11:02:12 markd Exp $
#

DISTNAME=		matplotlib-0.98.4
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		graphics python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=matplotlib/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://matplotlib.sourceforge.net/
COMMENT=		Matlab-style plotting package for Python

DEPENDS+=		${PYPKGPREFIX}-pytz>=2008b:../../time/py-pytz
DEPENDS+=		${PYPKGPREFIX}-dateutil>=1.2:../../time/py-dateutil

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED=	26 25 24

.include "../../lang/python/extension.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
