# $NetBSD: Makefile,v 1.10 2008/11/06 23:18:34 adrianp Exp $
#

DISTNAME=	opengrok-0.7
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.opensolaris.org/os/project/opengrok/files/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.opensolaris.org/os/project/opengrok/files/
COMMENT=	Fast and usable source code search and cross reference engine

DEPENDS+=	exctags-[0-9]*:../../devel/exctags
DEPENDS+=	unzip-[0-9]*:../../archivers/unzip
DEPENDS+=	zip-[0-9]*:../../archivers/zip

PKG_DESTDIR_SUPPORT=	user-destdir

.include "options.mk"

.if empty(PKG_OPTIONS:Mopengrok-build)
NO_BUILD=	YES
.endif

USE_JAVA=	run
USE_JAVA2=	yes

CONF_FILES=	${PREFIX}/share/examples/opengrok/paths.tsv \
		${PREFIX}/share/opengrok/paths.tsv

SUBST_CLASSES+=		run
SUBST_STAGE.run=	post-patch
SUBST_FILES.run=	run.sh run-quiet.sh
SUBST_SED.run=		-e "s|/usr/local/bin/ctags|${PREFIX}/bin/exctags|g"
SUBST_SED.run+=		-e "s|java|${PKG_JAVA_HOME}/bin/java|g"
SUBST_SED.run+=		-e "s|@PREFIX@|${PREFIX}|g"
SUBST_MESSAGE.run=	Fixing hardcoded paths.

pre-build:
	${CP} ${PREFIX}/lib/java/JFlex.jar ${WRKSRC}/lib

do-build:
	cd ${WRKSRC} && ${PREFIX}/bin/ant

post-build:
	${RM} -f ${WRKSRC}/lib/*.jar
	${CP} ${WRKSRC}/dist/lib/*.jar ${WRKSRC}/lib
	${CP} ${WRKSRC}/dist/opengrok.jar ${WRKSRC}
	${CP} ${WRKSRC}/dist/source.war ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/opengrok
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/opengrok/lib
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/opengrok

	${INSTALL_DATA} ${WRKSRC}/README.txt \
		${DESTDIR}${PREFIX}/share/opengrok
	${INSTALL_DATA} ${WRKSRC}/opengrok.jar \
		${DESTDIR}${PREFIX}/share/opengrok
	${INSTALL_DATA} ${WRKSRC}/source.war \
		${DESTDIR}${PREFIX}/share/opengrok
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar \
		${DESTDIR}${PREFIX}/share/opengrok/lib
	${INSTALL_DATA} ${WRKSRC}/paths.tsv \
		${DESTDIR}${PREFIX}/share/examples/opengrok
	${INSTALL_SCRIPT} ${WRKSRC}/run.sh \
		${DESTDIR}${PREFIX}/share/opengrok
	${INSTALL_SCRIPT} ${WRKSRC}/run-quiet.sh \
		${DESTDIR}${PREFIX}/share/opengrok

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
