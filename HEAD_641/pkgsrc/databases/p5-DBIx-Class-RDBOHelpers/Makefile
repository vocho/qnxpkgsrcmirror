# $NetBSD: Makefile,v 1.3 2008/12/03 05:44:50 seb Exp $

DISTNAME=	DBIx-Class-RDBOHelpers-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBIx-Class-RDBOHelpers/
COMMENT=	DBIC compat with Rose::DBx::Object::MoreHelpers

DEPENDS+=	p5-Data-Dump>=0:../../devel/p5-Data-Dump
DEPENDS+=	p5-DBICx-TestDatabase>=0:../../databases/p5-DBICx-TestDatabase

BUILD_DEPENDS+=	p5-DBIx-Class-[0-9]*:../../databases/p5-DBIx-Class

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/DBIx/Class/RDBOHelpers/.packlist

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
