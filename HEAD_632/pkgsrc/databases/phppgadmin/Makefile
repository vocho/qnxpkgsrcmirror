# $NetBSD: Makefile,v 1.21 2006/09/05 17:04:31 tv Exp $

DISTNAME=	phpPgAdmin-3.5.6
PKGNAME=	${DISTNAME:S/PgAdmin/pgadmin/}
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=phppgadmin/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://phppgadmin.sourceforge.net/
COMMENT=	Set of PHP-scripts to administer PostgreSQL over the WWW

DEPENDS+=	${PHP_PKG_PREFIX}-pgsql>=4.2.0:../../databases/php-pgsql

MESSAGE_SUBST+=	EGDIR=${EGDIR}

WRKSRC=		${WRKDIR}/${DISTNAME:C/-.*//}
NO_BUILD=	YES

PHPPGBASE=	${PREFIX}/share/phppgadmin
PHPPGHIER=	classes/HTML_TreeMenu/images help images/themes/default \
		libraries/adodb/datadict libraries/adodb/drivers \
		classes/database lang/recoded themes/default sql conf

EGDIR=		${PREFIX}/share/examples/phppgadmin
DOCDIR=		${PREFIX}/share/doc/phppgadmin
CONF_FILES=	${EGDIR}/config.inc.php-dist ${PHPPGBASE}/conf/config.inc.php
DOC_FILES=	CREDITS DEVELOPERS FAQ HISTORY INSTALL LICENSE TODO \
		TRANSLATORS
REQD_DIRS+=	${PHPPGBASE} ${PHPPGBASE}/conf

do-configure:
	@${SED} -e "s#/usr/bin/pg#${PREFIX}/bin/pg#" \
		${WRKSRC}/conf/config.inc.php-dist > \
			${WRKSRC}/conf/config.inc.php-dist.tmp
	@${MV} ${WRKSRC}/conf/config.inc.php-dist.tmp \
		${WRKSRC}/conf/config.inc.php-dist
	@${SED} -e "s#@PHPPGBASE@#${PHPPGBASE}#g" ${FILESDIR}/apache.conf-dist \
		> ${WRKDIR}/apache.conf

do-install:
	${INSTALL_DATA_DIR} ${PHPPGBASE}
	${INSTALL_DATA_DIR} ${EGDIR}

	for d in ${PHPPGHIER}; do \
	        ${INSTALL_DATA_DIR} ${PHPPGBASE}/$$d; \
	done

	${INSTALL_SCRIPT} ${WRKSRC}/*.* ${PHPPGBASE}
	${INSTALL_SCRIPT} ${WRKSRC}/classes/*.* ${PHPPGBASE}/classes
	${INSTALL_SCRIPT} ${WRKSRC}/classes/HTML_TreeMenu/*.* \
		${PHPPGBASE}/classes/HTML_TreeMenu
	${INSTALL_DATA} ${WRKSRC}/classes/HTML_TreeMenu/images/* \
		${PHPPGBASE}/classes/HTML_TreeMenu/images
	${INSTALL_SCRIPT} ${WRKSRC}/classes/database/* \
		${PHPPGBASE}/classes/database
	${INSTALL_SCRIPT} ${WRKSRC}/help/* ${PHPPGBASE}/help
	${INSTALL_SCRIPT} ${WRKSRC}/sql/* ${PHPPGBASE}/sql
	${INSTALL_DATA} ${WRKSRC}/images/themes/default/*.png \
		${PHPPGBASE}/images/themes/default
	${INSTALL_SCRIPT} ${WRKSRC}/lang/*.* ${PHPPGBASE}/lang
	${INSTALL_SCRIPT} ${WRKSRC}/lang/recoded/*.* ${PHPPGBASE}/lang/recoded
	${INSTALL_SCRIPT} ${WRKSRC}/libraries/*.php ${PHPPGBASE}/libraries
	${INSTALL_SCRIPT} ${WRKSRC}/libraries/adodb/*.php \
		${PHPPGBASE}/libraries/adodb
	${INSTALL_DATA} ${WRKSRC}/libraries/adodb/*.txt \
		${PHPPGBASE}/libraries/adodb
	${INSTALL_SCRIPT} ${WRKSRC}/libraries/adodb/datadict/* \
		${PHPPGBASE}/libraries/adodb/datadict
	${INSTALL_SCRIPT} ${WRKSRC}/libraries/adodb/drivers/* \
		${PHPPGBASE}/libraries/adodb/drivers
	${INSTALL_DATA} ${WRKSRC}/themes/default/global.css \
		${PHPPGBASE}/themes/default
	${INSTALL_DATA} ${WRKSRC}/conf/config.inc.php-dist ${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/apache.conf ${EGDIR}

	${INSTALL_DATA_DIR} ${DOCDIR}
	for f in ${DOC_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${DOCDIR}; \
	done

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
