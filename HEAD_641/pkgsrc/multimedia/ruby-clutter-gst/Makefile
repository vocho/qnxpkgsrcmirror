# $NetBSD: Makefile,v 1.1.1.1 2008/12/16 12:34:31 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-clutter-gst-${VERSION}
COMMENT=		Ruby binding for Clutter GStreamer library
CATEGORIES=		multimedia

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${RUBY_PKGPREFIX}-clutter-core>=${VERSION}:../../graphics/ruby-clutter-core
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gstreamer-[0-9]*:../../multimedia/ruby-gnome2-gstreamer

RUBY_EXTCONF_SUBDIRS=	clutter-gst

USE_TOOLS+=	pkg-config

.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../multimedia/clutter-gst/buildlink3.mk"
.include "../../graphics/ruby-clutter/Makefile.common"
