# $NetBSD: Makefile,v 1.19 2007/01/07 09:14:10 rillig Exp $
#

DISTNAME=		skey-1.1.5
PKGREVISION=		2
CATEGORIES=		security
MASTER_SITES=		http://www.sparc.spb.su/solaris/skey/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Port of OpenBSD s/key implementation

USE_TOOLS+=		gmake perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONF_FILES+=		${PREFIX}/share/examples/skey/skeykeys \
			${PKG_SYSCONFDIR}/skeykeys

SUBST_CLASSES+=		perl
SUBST_MESSAGE.perl=	fixing perl path
SUBST_STAGE.perl=	post-extract
SUBST_FILES.perl=	skeyprune.pl
SUBST_SED.perl=		-e "s,^\#!/usr/bin/perl,\#!${PERL5},"

INSTALLATION_DIRS=	bin include lib ${PKGMANDIR}/man1 ${PKGMANDIR}/man8

post-install:
	${RANLIB} ${PREFIX}/lib/libskey.a

.include "../../mk/bsd.pkg.mk"
