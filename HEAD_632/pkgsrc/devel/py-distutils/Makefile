# $NetBSD: Makefile,v 1.6 2007/02/22 19:01:17 wiz Exp $
#

DISTNAME=	Distutils-1.0.2
PKGNAME=	${PYPKGPREFIX}-distutils-1.0.2
CATEGORIES=	devel python
MASTER_SITES=	http://www.python.org/community/sigs/current/distutils-sig/download/

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.python.org/community/sigs/current/distutils-sig/
COMMENT=	Distribution Utilities for Python

PYTHON_VERSIONS_ACCEPTED= 15
PYSITELIB=	lib/python1.5/site-packages
PLIST_SUBST+=	PYSITELIB=${PYSITELIB:Q}
PYTHON_DISTUTILS_BOOTSTRAP=	yes

do-build:
	cd ${WRKSRC} && ${PYTHONBIN} setup.py build

do-install:
	cd ${WRKSRC} && ${PYTHONBIN} setup.py install

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
