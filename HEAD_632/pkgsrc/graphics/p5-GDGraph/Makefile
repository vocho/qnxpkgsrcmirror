# $NetBSD: Makefile,v 1.19 2007/05/19 14:07:30 heinz Exp $
#

DISTNAME=	GDGraph-1.44
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5gdg
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://cpan.uwinnipeg.ca/htdocs/GDGraph/GD/Graph.html
COMMENT=	GDGraph is a package to generate charts, using Lincoln Stein's GD.pm

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-GD>=1.18:../../graphics/p5-GD
DEPENDS+=		p5-GDTextUtil>=0.80:../../graphics/p5-GDTextUtil

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/GD/Graph/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
