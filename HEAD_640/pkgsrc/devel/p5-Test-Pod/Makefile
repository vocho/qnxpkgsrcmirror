# $NetBSD: Makefile,v 1.16 2008/10/19 19:18:01 he Exp $

DISTNAME=		Test-Pod-1.26
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
SVR4_PKGNAME=		p5tp
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Pod/
COMMENT=		Perl5 module to check for POD errors in files

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-Pod-Simple>=3.02nb1:../../textproc/p5-Pod-Simple
DEPENDS+=		{p5-Test-Simple>=0.62,perl>=5.8.8}:../../devel/p5-Test-Simple

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/Pod/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
