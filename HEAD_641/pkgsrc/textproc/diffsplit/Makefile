# $NetBSD: Makefile,v 1.2 2009/07/07 22:12:32 joerg Exp $
# FreeBSD Id: ports/textproc/diffsplit/Makefile,v 1.7 2006/12/22 13:43:54 barner Exp

DISTNAME=	diffsplit
PKGNAME=	diffsplit-1.0
PKGREVISION=	1
CATEGORIES=	textproc devel misc
MASTER_SITES=	http://www.pathname.com/~quinlan/software/diffsplit/
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pathname.com/~quinlan/software/diffsplit/
COMMENT=	Splits a unified diff into pieces which patch one file each

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	YES
WRKSRC=		${WRKDIR}
REPLACE_PERL=	diffsplit
USE_TOOLS+=	perl:run

INSTALLATION_DIRS=	bin

do-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/diffsplit ${WRKDIR}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/diffsplit ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
