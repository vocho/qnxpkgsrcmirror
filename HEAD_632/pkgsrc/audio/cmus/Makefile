# $NetBSD: Makefile,v 1.9 2007/11/19 00:10:31 hubertf Exp $
#

DISTNAME=		cmus-2.1.0
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		http://mirror.greaterscope.net/cmus/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		webmaster@deepblack24.de
HOMEPAGE=		http://onion.dynserv.net/~timo/files/
COMMENT=		Cmus is an ncurses based mp3/ogg player with a lot of features

HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

CONFIGURE_ARGS+=	prefix=${PREFIX}
CONFIGURE_ARGS+=	CONFIG_ALSA=n
CONFIGURE_ARGS+=	CONFIG_OSS=y
CONFIGURE_ARGS+=	mandir=${PREFIX}/${PKGMANDIR}/

.if exists(/usr/include/sys/audioio.h)
PLIST_SUBST+=	SUN=""
.else
PLIST_SUBST+=	SUN="@comment "
.endif

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	CONFIG_SUN=y
.endif

.include "options.mk"

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
