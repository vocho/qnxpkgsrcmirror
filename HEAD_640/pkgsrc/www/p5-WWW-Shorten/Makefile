# $NetBSD: Makefile,v 1.1.1.1 2009/02/03 06:17:00 seb Exp $

DISTNAME=	WWW-Shorten-2.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/WWW-Shorten/
COMMENT=	Perl 5 module interface to URL shortening sites

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/WWW/Shorten/.packlist

DEPENDS+=	p5-Config-Auto-[0-9]*:../../devel/p5-Config-Auto
DEPENDS+=	p5-URI>=1.27:../../www/p5-URI
DEPENDS+=	p5-libwww>=5.750:../../www/p5-libwww

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
