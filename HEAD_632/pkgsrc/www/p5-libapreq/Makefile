# $NetBSD: Makefile,v 1.18 2006/06/02 18:28:00 joerg Exp $

DISTNAME=	libapreq-1.33
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5lap
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://httpd.apache.org/apreq/
COMMENT=	Lots of Apache specific httpd handling modules

DEPENDS+=	p5-Apache-Test>=1.13:../../www/p5-Apache-Test

PERL5_PACKLIST=	auto/libapreq/.packlist

LDFLAGS+=	${COMPILER_RPATH_FLAG}auto/libapreq

.include "../../lang/perl5/module.mk"
.include "../../www/ap-perl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
