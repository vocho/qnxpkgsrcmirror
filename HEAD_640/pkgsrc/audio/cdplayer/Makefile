# $NetBSD: Makefile,v 1.15 2008/09/30 15:50:24 joerg Exp $
#

DISTNAME=	cdplayer-0.4.2
PKGREVISION=	7
CATEGORIES=	audio gnustep
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gsburn/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gsburn.sourceforge.net/
COMMENT=	GNUstep CD player with CDDB support

WRKSRC=		${WRKDIR}/${PKGBASE}
USE_LANGUAGES=	objc
USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile
MAKE_ENV+=	ADDITIONAL_CPPFLAGS="-Wno-import"
MAKE_ENV+=	GNUSTEP_INSTALLATION_DIR=${PREFIX}/share/GNUstep/Local/

do-configure:
	${LN} -s ${BUILDLINK_DIR}/${GNUSTEP_SUBDIR}/Local/Library/Frameworks/PrefsModule.framework/Versions/0/Headers ${WRKSRC}/AudioCD/AudioCDPrefs/PrefsModule

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/CDPlayer
	${INSTALL_DATA} ${WRKSRC}/CDPlayer/AudioCDProtocol.h		\
			${PREFIX}/include/CDPlayer

.include "../../audio/libcdaudio/buildlink3.mk"
.include "../../audio/cddb-bundle/buildlink3.mk"
.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../x11/gnustep-preferences/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
