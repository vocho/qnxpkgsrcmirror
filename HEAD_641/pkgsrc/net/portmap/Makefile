# $NetBSD: Makefile,v 1.2 2008/06/12 02:14:41 joerg Exp $

DISTNAME=	portmap_4
PKGNAME=	portmap-4
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.porcupine.org/pub/security/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	ftp://ftp.porcupine.org/pub/security/index.html
COMMENT=	RPC portmapper with access control

PKG_DESTDIR_SUPPORT=	user-destdir

# TODO: maybe look at portmap_5beta ?

# XXX allow this to install on NetBSD, because this also
# XXX provides pmap_dump and pmap_set

INSTALLATION_DIRS+=	sbin share/doc/portmap
MAKE_FLAGS+=	WRAP_DIR=${BUILDLINK_PREFIX.tcp_wrappers}/lib
NO_CONFIGURE=	yes
RCD_SCRIPTS=	portmap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/portmap ${DESTDIR}${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/pmap_dump ${DESTDIR}${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/pmap_set ${DESTDIR}${PREFIX}/sbin/
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/portmap/

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
