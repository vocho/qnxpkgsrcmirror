# $NetBSD: Makefile,v 1.32 2013/07/12 10:45:00 jperkin Exp $

DISTNAME=		openntpd-3.9p1
PKGREVISION=		4
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.openbsd.org/pub/OpenBSD/OpenNTPD/ \
			ftp://ftp3.usa.openbsd.org/pub/OpenBSD/OpenNTPD/ \
			ftp://ftp.belnet.be/packages/openbsd/OpenNTPD/ \
			ftp://ftp.jaist.ac.jp/pub/OpenBSD/OpenNTPD/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.openntpd.org/
COMMENT=		Free implementation of the Network Time Protocol

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=		ntp-[0-9]*

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=			${PREFIX}/share/examples/openntpd
CONF_FILES=		${EGDIR}/ntpd.conf ${PKG_SYSCONFDIR}/ntpd.conf

RCD_SCRIPTS=		openntpd
PKG_GROUPS=		_ntp
PKG_USERS=		_ntp:_ntp
PKG_HOME._ntp=		${VARBASE}/chroot/ntpd

BUILD_DEFS+=		VARBASE

OWN_DIRS=		${VARBASE}/chroot/ntpd
AUTO_MKDIRS=		yes

INSTALLATION_DIRS+=	sbin ${PKGMANDIR}/man5 ${PKGMANDIR}/man8 ${EGDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ntpd ${DESTDIR}${PREFIX}/sbin/ntpd
	${INSTALL_MAN} ${WRKSRC}/ntpd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/ntpd.8
	${INSTALL_MAN} ${WRKSRC}/ntpd.conf.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/ntpd.conf.5
	${INSTALL_DATA} ${WRKSRC}/ntpd.conf ${DESTDIR}${EGDIR}/ntpd.conf

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
