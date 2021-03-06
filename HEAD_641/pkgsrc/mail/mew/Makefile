# $NetBSD: Makefile,v 1.78 2009/08/14 17:21:20 minskim Exp $

DISTNAME=	mew-6.2
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.mew.org/Release/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.mew.org/
COMMENT=	Messaging in the Emacs World

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	${MEW_CONTRIB_DIR:C|^${PREFIX}/||}

CONFLICTS+=	mew-xemacs-[0-9]* incm-[0-9]*

INFO_FILES=	yes

GNU_CONFIGURE=	yes

EMACS_VERSIONS_ACCEPTED=	emacs23 emacs23nox emacs22 emacs22nox emacs21 emacs21nox
EMACS_MODULES+=			base

MEW_CONTRIB_DIR=${EMACS_LISPPREFIX}/mew/contrib

MAKE_FLAGS+=	DESTDIR=${DESTDIR:Q}
MAKE_FLAGS+=	prefix=${PREFIX:Q}
MAKE_FLAGS+=	exec_prefix=${PREFIX:Q}
MAKE_FLAGS+=	EMACS=${EMACS_BIN:Q}
MAKE_FLAGS+=	elispdir=${EMACS_LISPPREFIX:Q}/mew
MAKE_FLAGS+=	etcdir=${EMACS_ETCPREFIX:Q}/mew
MAKE_FLAGS+=	infodir=${EMACS_INFOPREFIX:Q}
MAKE_FLAGS+=	mandir=${PREFIX:Q}/${PKGMANDIR:Q}/man1
CONFIGURE_ARGS+=	--with-etcdir=${EMACS_ETCPREFIX}/mew

SUBST_CLASSES+=		local
SUBST_STAGE.local=	post-configure
SUBST_FILES.local=	Makefile bin/configure info/Makefile
SUBST_SED.local=	-e 's|/usr/local|${PREFIX}|g'

post-configure:
	${MV} ${WRKSRC}/mew-key.el ${WRKSRC}/mew-key.el.1
	${SED} -e 's|@ICONDIR@|${EMACS_ETCPREFIX}/mew|g' \
		${WRKSRC}/mew-key.el.1 > ${WRKSRC}/mew-key.el

post-install:
	${INSTALL_DATA} ${WRKSRC}/contrib/* ${DESTDIR}${MEW_CONTRIB_DIR}

.include "../../devel/zlib/buildlink3.mk"
.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
