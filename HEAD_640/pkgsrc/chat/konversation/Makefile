# $NetBSD: Makefile,v 1.18 2008/10/12 04:14:58 tonnerre Exp $
#

DISTNAME=	konversation-1.1
CATEGORIES=	chat kde
MASTER_SITES=	http://download.berlios.de/konversation/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://konversation.kde.org/
COMMENT=	KDE IRC Client

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	gmake perl msgfmt
USE_LANGUAGES=	c c++

REPLACE_PERL+=		konversation/src/konversation-0.19-appearance.pl \
			konversation/src/konversation-0.19-colorcodes.pl \
			konversation/src/konversation-0.19-colors.pl \
			konversation/src/konversation-0.19-custombrowser.pl \
			konversation/src/konversation-0.19-notifylists.pl \
			konversation/src/konversation-0.19-sortorder.pl \
			konversation/src/konversation-0.19-tabplacement.pl \
			konversation/src/konversation-0.20-customfonts.pl \
			konversation/src/konversation-0.20-quickbuttons.pl
REPLACE_BASH+=		konversation/scripts/mail
USE_TOOLS+=		bash:run

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
DEPENDS+=		psmisc>=20.1:../../sysutils/psmisc
.endif

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
CONFIGURE_ARGS+=	--disable-threading
.endif

.include "../../mk/bsd.pkg.mk"
