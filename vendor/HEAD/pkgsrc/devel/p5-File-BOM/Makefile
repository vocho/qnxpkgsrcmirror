# $NetBSD: Makefile,v 1.6 2013/05/31 12:40:19 wiz Exp $

DISTNAME=	File-BOM-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-BOM/
COMMENT=	Utilities for handling Byte Order Marks
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Readonly-[0-9]*:../../devel/p5-Readonly

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=	auto/File/BOM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
