# $NetBSD: Makefile,v 1.15 2006/10/04 22:04:09 wiz Exp $

DISTNAME=	instiki-0.9.2
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://rubyforge.org/frs/download.php/2515/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://instiki.org/show/HomePage
COMMENT=	Wiki clone that focuses on simple installation and running

NO_BUILD=	yes

RCD_SCRIPTS=	instiki
FILES_SUBST+=	RUBY=${RUBY:Q}

REPLACE_RUBY=		instiki

INSTIKI_DIR=	${PREFIX}/share/${PKGBASE}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	app/controllers/wiki.rb
SUBST_SED.paths=							\
	-e 's,File.dirname(__FILE__) + "/../../storage,"${VARBASE}/instiki,g'

post-patch:
	${MV} ${WRKSRC}/instiki ${WRKSRC}/instiki.tmp
	${TR} -d '\015' < ${WRKSRC}/instiki.tmp > ${WRKSRC}/instiki

do-install:
	${INSTALL_DATA_DIR} ${INSTIKI_DIR}
.for d in app libraries
	cd ${WRKSRC} && ${CP} -R ${d} ${INSTIKI_DIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${INSTIKI_DIR}/${d}
.endfor
	${FIND} ${INSTIKI_DIR} -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${INSTIKI_DIR} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}
	${INSTALL_SCRIPT} ${WRKSRC}/instiki ${INSTIKI_DIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${PKGBASE}

.include "../../lang/ruby/replace.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
