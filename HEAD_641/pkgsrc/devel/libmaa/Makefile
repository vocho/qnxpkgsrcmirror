# $NetBSD: Makefile,v 1.2 2009/03/21 16:07:02 darcy Exp $

DISTNAME=		libmaa-1.1.0
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dict/} \
                        ftp://ftp.dict.org/pub/dict/

MAINTAINER=		vle@gmx.net
HOMEPAGE=		http://www.dict.org/
COMMENT=		General purpose data structures and functions

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=		lib
TEST_TARGET=		test

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

PKGDOCDIR=		${PREFIX}/share/doc/libmaa
INSTALLATION_DIRS+=	${PKGDOCDIR} lib include

EXTRA_DOC_FILES=	COPYING.LIB README doc/libmaa.600dpi.ps

post-install:
.for i in ${EXTRA_DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/"${i}" ${DESTDIR}${PKGDOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
