# $NetBSD: Makefile,v 1.13 2008/08/17 05:10:59 dholland Exp $

DISTNAME=	libtecla-1.6.1
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.astro.caltech.edu/~mcs/tecla/

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://www.astro.caltech.edu/~mcs/tecla/
COMMENT=	Interactive command line editing facilities

WRKSRC=			${WRKDIR}/${PKGBASE}
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
BUILD_TARGET=		default

.include "../../mk/bsd.prefs.mk"

# reentrant causes compilation problems
.if ${OPSYS} != "SunOS"
CONFIGURE_ENV+=		tecla_cv_reentrant=no
.endif

.include "../../mk/bsd.pkg.mk"
