# $NetBSD: Makefile,v 1.3 2006/07/02 13:19:53 markd Exp $
#

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mchittur@cs.nmsu.edu
HOMEPAGE=	${R_HOMEPAGE_BASE}/genetics.html
COMMENT=	Classes and methods for handling genetic data

R_PKGNAME=	genetics
R_PKGVER=	1.2.0

DEPENDS+=	R-combinat>=0.0.6:../../math/R-combinat
DEPENDS+=	R-gdata>=2.1.2:../../math/R-gdata
DEPENDS+=	R-mvtnorm>=0.7.2:../../math/R-mvtnorm

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
