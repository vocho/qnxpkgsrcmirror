# $NetBSD: Makefile,v 1.44 2008/07/14 12:56:08 joerg Exp $

DISTNAME=	kdeadmin-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	System administration tools for the KDE integrated X11 desktop

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/kde3/Makefile.kde3"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--with-shadow
.else
CONFIGURE_ARGS+=	--without-shadow
.endif
CONFIGURE_ENV+=		DO_NOT_COMPILE=ksysv

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
