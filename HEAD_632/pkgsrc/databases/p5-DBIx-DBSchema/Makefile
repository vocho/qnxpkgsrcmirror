# $NetBSD: Makefile,v 1.3 2007/06/08 08:37:15 wiz Exp $
#

DISTNAME=	DBIx-DBSchema-0.31
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBIx-DBSchema/
COMMENT=	Database-independent schema objects

DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI
DEPENDS+=	p5-FreezeThaw-[0-9]*:../../devel/p5-FreezeThaw

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/DBIx/DBSchema/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
