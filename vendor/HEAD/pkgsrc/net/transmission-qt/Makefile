# $NetBSD: Makefile,v 1.4 2013/06/06 12:54:57 wiz Exp $

PKGNAME=	${DISTNAME:C:-:-qt-:}
PKGREVISION=	3

USE_LANGUAGES+=		c c++
MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}${PREFIX}

CONFIGURE_ARGS+=	--disable-cli --disable-daemon --without-gtk

CONFLICTS+=		Transmission-gui-[0-9]*

.include "../../net/transmission/Makefile.common"

post-build:
	cd ${WRKSRC}/qt && ${SETENV} ${MAKE_ENV} ${QTDIR}/bin/qmake qtr.pro
	cd ${WRKSRC}/qt && ${SETENV} ${MAKE_ENV} make

do-install:
	cd ${WRKSRC}/qt && ${SETENV} ${INSTALL_ENV} make install

.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
