# $NetBSD: Makefile,v 1.19 2008/12/17 02:19:59 christos Exp $
#

# Note: The file ftp://ftp.icb.net/pub/icb/icb-0.9grok2.tar.gz is way
#	older than this here. It's got no readline support, tcl, ... - HF
DISTNAME=		icb-5.0.9
PKGNAME=		icb-5.0.9pl1
PKGREVISION=		5
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		cjs@NetBSD.org
HOMEPAGE=		http://www.icb.net/
COMMENT=		Internet CB - a mostly-defunct chat client

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

NO_SRC_ON_FTP=		already in MASTER_SITE_LOCAL

INSTALLATION_DIRS=	bin ${ICBLIBDIR} ${EGDIR}
EGDIR=			${PREFIX}/share/examples/icb
ICBLIBDIR=		${PREFIX}/libdata/icb
CONF_FILES+=		${EGDIR}/icbserverdb ${PREFIX}/libdata/icbserverdb

post-extract:
	${RM} -f ${WRKSRC}/tcl/string.h

do-configure:
	${SED} -e "s|@PREFIX@|${PREFIX}|g" ${FILESDIR}/config >${WRKSRC}/config

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icb/icb ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/libdata/icb
	${INSTALL_DATA} ${WRKSRC}/contrib/bartender ${DESTDIR}${ICBLIBDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/confuse ${DESTDIR}${ICBLIBDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/echofile ${DESTDIR}${ICBLIBDIR}
	${INSTALL_DATA} ${WRKSRC}/icbserverdb ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sample.icbrc ${DESTDIR}${EGDIR}

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
