# $NetBSD: Makefile,v 1.4 2006/06/01 21:03:43 joerg Exp $

DISTNAME=	wsbasic-1_2_5
PKGNAME=	${DISTNAME:S/_/./g}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wsbasic/}

MAINTAINER=	ghen@NetBSD.org
HOMEPAGE=	http://wsbasic.sourceforge.net/
COMMENT=	Simple BASIC interpreter

USE_LANGUAGES=	c++

SUBST_CLASSES+=			interpreter
SUBST_STAGE.interpreter=	pre-install
SUBST_FILES.interpreter=	scripts/*.b
SUBST_SED.interpreter=		-e 's,^\#!\.\./wsbasic,\#!${PREFIX}/bin/wsbasic,'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wsbasic ${PREFIX}/bin/
	${INSTALL_SCRIPT_DIR} ${PREFIX}/share/wsbasic
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/*.b ${PREFIX}/share/wsbasic/
	${INSTALL_DATA} ${WRKSRC}/scripts/*.txt ${PREFIX}/share/wsbasic/

.include "../../mk/bsd.pkg.mk"
