# $NetBSD: Makefile,v 1.10 2005/08/06 06:19:23 jlam Exp $
#

DISTNAME=		Business-UPS-1.13
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
SVR4_PKGNAME=		p5buu
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=		eric@cirr.com
HOMEPAGE=		http://theoryx5.uwinnipeg.ca/CPAN/data/Business-UPS/README.html
COMMENT=		Perl5 module to handle UPS rate calculation and package tracking

DEPENDS+=		p5-libwww>=5.48:../../www/p5-libwww

PERL5_PACKLIST=		auto/Business/UPS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
