# $NetBSD: Makefile,v 1.13 2006/03/04 21:30:47 jlam Exp $
#

DISTNAME=	igerman98-20030222
PKGNAME=	ispell-german-20030222
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://j3e.de/ispell/igerman98/dict/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://j3e.de/ispell/igerman98/
COMMENT=	German dictionary for interactive spelling checker

DEPENDS+=	ispell-base>=3.1.20nb1:../../textproc/ispell-base

BUILD_TARGET=	german.hash
USE_TOOLS+=	gmake perl
REPLACE_PERL=	bin/dic2iso.pl bin/grepl bin/sq.pl bin/myspellfixprefix.pl \
		bin/clear_affix.pl bin/unsq.pl bin/uniqflag.pl

INSTALLATION_DIRS=	lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/german.aff ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/german.hash ${PREFIX}/lib
	(cd ${PREFIX}/lib && ${LN} -s german.aff deutsch.aff)
	(cd ${PREFIX}/lib && ${LN} -s german.hash deutsch.hash)
	(cd ${PREFIX}/lib && ${LN} -s german.aff ngerman.aff)
	(cd ${PREFIX}/lib && ${LN} -s german.hash ngerman.hash)

.include "../../mk/bsd.pkg.mk"
