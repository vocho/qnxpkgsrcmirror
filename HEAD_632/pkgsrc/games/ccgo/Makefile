# $NetBSD: Makefile,v 1.27 2007/09/21 13:03:42 wiz Exp $

DISTNAME=	ccgo-0.3.6.2
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://ccdw.org/~cjj/prog/ccgo/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ccdw.org/~cjj/prog/ccgo/
COMMENT=	Go board with IGS and gnugo interface

DEPENDS+=	gnugo>=3.4:../../games/gnugo

USE_LANGUAGES=		c c++
USE_TOOLS+=		msgfmt pkg-config
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

SUBST_CLASSES+=		ccgo
SUBST_STAGE.ccgo=	pre-configure
SUBST_FILES.ccgo=	game_setup.cc settings.cc
SUBST_MESSAGE.ccgo=	Fixing paths to gnugo.
SUBST_SED.ccgo=		-e 's|/usr/games/gnugo|${PREFIX.gnugo}/bin/gnugo|g'

EVAL_PREFIX+=		PREFIX.gnugo
PREFIX.gnugo_DEFAULT=	${LOCALBASE}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gconfmm/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
