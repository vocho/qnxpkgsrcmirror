# $NetBSD: Makefile,v 1.22 2009/07/26 18:38:14 drochner Exp $

DISTNAME=		gnome-media-2.26.0
PKGREVISION=		1
CATEGORIES=		multimedia gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-media/2.26/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Set of audio/multimedia applications for GNOME2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config xgettext

GCONF_SCHEMAS+=	gnome-audio-profiles.schemas
GCONF_SCHEMAS+=	gnome-sound-recorder.schemas

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/GConf-ui/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgnome+=		libgnome>=2.13.7
.include "../../devel/libgnome/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgnomeui+=		libgnomeui>=2.13.2
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.gst-plugins0.10-base+=	gst-plugins0.10-base>=0.10.3
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
BUILDLINK_API_DEPENDS.gstreamer0.10+=		gstreamer0.10>=0.10.3
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=			gtk2+>=2.10.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
