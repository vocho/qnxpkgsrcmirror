# $NetBSD: Makefile,v 1.4 2008/06/20 01:09:11 joerg Exp $
#

DISTNAME=		tinycdb_0.76
PKGNAME=		${DISTNAME:S/_/-/}
CATEGORIES=		databases
MASTER_SITES=		http://www.corpit.ru/mjt/tinycdb/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.corpit.ru/mjt/tinycdb.html
COMMENT=		Create and read constant databases

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		cdb-[0-9]*

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	Makefile
SUBST_SED.paths=	-e 's|@PREFIX@|${PREFIX}|g'
SUBST_SED.paths+=	-e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g'
SUBST_SED.paths+=	-e 's|@PKGMANDIR@|${PKGMANDIR}|g'
SUBST_MESSAGE.paths=	Configuring pkgsrc paths.

.include "../../mk/bsd.pkg.mk"
