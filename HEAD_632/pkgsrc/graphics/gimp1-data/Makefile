# $NetBSD: Makefile,v 1.12 2007/12/02 12:05:45 wiz Exp $
#

DISTNAME=	gimp-data-extras-1.2.0
PKGNAME=	gimp-data-1.2
PKGREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/v1.2/v1.2.5/ \
		ftp://ftp.fu-berlin.de/unix/X11/graphics/gimp/v1.2/v1.2.5/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gimp.org/
COMMENT=	GNU Image Manipulation Program (extra brushes and patterns)

CONFLICTS+=	gimp<=1.2.3 gimp>=2.0.0

GNU_CONFIGURE=	YES

.include "../../graphics/gimp1-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
