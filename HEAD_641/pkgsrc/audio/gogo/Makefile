# $NetBSD: Makefile,v 1.19 2009/05/19 08:59:03 wiz Exp $
#

DISTNAME=		gogo239b
PKGNAME=		gogo-2.39.1
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		http://homepage1.nifty.com/herumi/soft/gogo2/src/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://homepage1.nifty.com/herumi/gogo_e.html
COMMENT=		Very fast lame-based mp3 encoder, i386 only
LICENSE=		unclear-patent-claims

RESTRICTED=		Source based on patent protected Fraunhofer code
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm

ONLY_FOR_PLATFORM=	*-*-i386

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake

.include "../../mk/bsd.prefs.mk"

.if (${OBJECT_FMT} == "a.out")
MAKE_FLAGS+=	ASFLAGS="-f aoutb -D__unix__ -DAOUT ${E3DN}"
.else
MAKE_FLAGS+=	ASFLAGS="-f elf -D__unix__ ${E3DN}"
.endif

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gogo ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/gogo
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DESTDIR}${PREFIX}/share/doc/gogo

.include "../../mk/bsd.pkg.mk"
