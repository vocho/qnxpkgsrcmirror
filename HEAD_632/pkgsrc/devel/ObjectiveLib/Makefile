# $NetBSD: Makefile,v 1.7 2006/07/22 05:10:54 rillig Exp $
#

DISTNAME=	ObjectiveLib-0.9
PKGREVISION=	1
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=objectivelib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://objectivelib.sourceforge.net/
COMMENT=	Object containers and generic algorithms for Objective-C

USE_LANGUAGES=	objc

WRKSRC=		${WRKDIR}

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
