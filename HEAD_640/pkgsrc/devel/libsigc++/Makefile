# $NetBSD: Makefile,v 1.30 2008/10/16 21:49:12 wiz Exp $

DISTNAME=	libsigc++-2.2.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libsigc++/2.2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bsieker@freenet.de
HOMEPAGE=	http://libsigc.sourceforge.net/
COMMENT=	Type-safe callback system for C++ programs

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gm4 gmake
GNU_CONFIGURE=		yes

CONFLICTS+=		libsigc++2-[0-9]*

# supported according to the file README
GCC_REQD+=		3.2
# use something that can extract long filenames in GNU format on NetBSD 1.6.x
EXTRACT_USING=		bsdtar

PKGCONFIG_OVERRIDE=	sigc++-2.0.pc.in

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--disable-threads
.endif

INSTALLATION_DIRS= include/sigc++-2.0/sigc++/adaptors/lambda/macros \
	include/sigc++-2.0/sigc++/adaptors/macros \
	include/sigc++-2.0/sigc++/functors/macros \
	include/sigc++-2.0/sigc++/macros

.include "../../mk/bsd.pkg.mk"
