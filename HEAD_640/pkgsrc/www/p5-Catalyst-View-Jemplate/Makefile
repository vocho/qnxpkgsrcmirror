# $NetBSD: Makefile,v 1.2 2008/10/19 19:19:07 he Exp $

DISTNAME=	Catalyst-View-Jemplate-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-View-Jemplate/
COMMENT=	Jemplate view class for Catalyst

DEPENDS+=	p5-Catalyst-Runtime>=5.50:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-File-Find-Rule-[0-9]*:../../devel/p5-File-Find-Rule
DEPENDS+=	p5-Jemplate>=0.19:../../www/p5-Jemplate

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/View/Jemplate/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
