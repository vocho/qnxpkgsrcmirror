# $NetBSD: Makefile,v 1.4 2008/06/19 14:56:14 taca Exp $

DISTNAME=	itexToMML
PKGNAME=	${RUBY_PKGPREFIX}-itex2MML-${ITEX2MML_VERSION}
PKGREVISION=	1
CATEGORIES=	textproc ruby
MASTER_SITES=	http://golem.ph.utexas.edu/~distler/blog/files/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://golem.ph.utexas.edu/~distler/blog/itex2MML.html
COMMENT=	Ruby binding for itex2MML

BUILD_DEPENDS+=	swig>=1.3:../../devel/swig

DIST_SUBDIR=	itex2MML-${ITEX2MML_VERSION}
USE_TOOLS+=	bison flex gmake
WRKSRC=		${WRKDIR}/${DISTNAME}/itex-src

ITEX2MML_VERSION=	1.2.3
MAKE_ENV+=		RUBY=${RUBY:Q}
RUBY_HAS_ARCHLIB=	yes

BUILD_TARGET=	ruby
INSTALL_TARGET=	install_ruby

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
