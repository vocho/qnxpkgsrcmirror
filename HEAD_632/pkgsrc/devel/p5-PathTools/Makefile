# $NetBSD: Makefile,v 1.4 2007/10/27 12:20:26 wiz Exp $

DISTNAME=	PathTools-3.25
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/PathTools/
COMMENT=	Perl module for portably manipulating file specifications

DEPENDS+=	p5-Scalar-List-Utils>=1.14:../../devel/p5-Scalar-List-Utils

CONFLICTS+=	p5-File-Spec-[0-9]*

CONFIGURE_ARGS+=	DEFINE="-DHAS_GETCWD"

PERL5_PACKLIST=	auto/Cwd/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
