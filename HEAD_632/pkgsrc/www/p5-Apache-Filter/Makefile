# $NetBSD: Makefile,v 1.17 2006/06/02 18:28:00 joerg Exp $

DISTNAME=	Apache-Filter-1.022
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
SVR4_PKGNAME=	p5afi
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~kwilliams/Apache-Filter-1.022/
COMMENT=	Perl5 module to alter the output of previous Apache handlers

PERL5_PACKLIST=		auto/Apache/Filter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../www/ap-perl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
