# $NetBSD: Makefile,v 1.3 2008/11/30 21:30:12 seb Exp $

DISTNAME=	Rose-DBx-Object-MoreHelpers-0.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Rose-DBx-Object-MoreHelpers/
COMMENT=	More mixin helpers for RDBO

DEPENDS+=	p5-Rose-DB-Object>=0.770:../../databases/p5-Rose-DB-Object
DEPENDS+=	p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Rose/DBx/Object/MoreHelpers/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
