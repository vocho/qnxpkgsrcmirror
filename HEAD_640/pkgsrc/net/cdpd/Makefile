# $NetBSD: Makefile,v 1.15 2008/06/20 01:09:30 joerg Exp $
#

DISTNAME=	cdpd-1.0.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.lexa.ru/pub/domestic/snar/

MAINTAINER=	explorer@NetBSD.org
COMMENT=	Simple daemon to send Cisco Discovery Protocol packets

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=       pre-configure
SUBST_FILES.conf=       configure
SUBST_SED.conf=         -e "s|libnet-config|libnet10-config|g"
SUBST_MESSAGE.conf=     Fixing configuration script.

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cdpd ${DESTDIR}${PREFIX}/sbin/cdpd
	${INSTALL_DATA} ${WRKSRC}/cdpd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/cdpd.8

.include "../../devel/libnet10/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
