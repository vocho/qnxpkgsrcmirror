# $NetBSD: Makefile,v 1.9 2006/10/02 19:51:37 abs Exp $
#

DISTNAME=	rsnapshot-1.2.9
CATEGORIES=	net
MASTER_SITES=	http://www.rsnapshot.org/downloads/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.rsnapshot.org/
COMMENT=	Filesystem snapshot utility

DEPENDS+=	rsync>=2.3.1:../../net/rsync
DEPENDS+=	p5-Lchown>=0.07:../../sysutils/p5-Lchown

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl:run

.include "../../mk/bsd.prefs.mk"

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
DOCDIR=		${PREFIX}/share/doc/${PKGBASE}

CONF_FILES+=	${EGDIR}/rsnapshot.conf.default \
		${PKG_SYSCONFDIR}/rsnapshot.conf

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}
CONFIGURE_ARGS+=	--with-rsync=${LOCALBASE}/bin/rsync

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rsnapshot ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/rsnapshot.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/rsnapshot.conf.default ${EGDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
