# $NetBSD: Makefile,v 1.33 2009/07/22 09:01:53 wiz Exp $

DISTNAME=		gtk-engines-0.12
PKGREVISION=		9
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gtk-engines/0.12/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Theme engines for GTK+

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		gtk2-engines-*

GNU_CONFIGURE=		yes
USE_X11BASE=		yes
USE_LIBTOOL=		yes
SHLIBTOOL_OVERRIDE=	# empty

.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
