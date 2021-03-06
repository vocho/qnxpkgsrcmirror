# $NetBSD: Makefile,v 1.44 2007/12/01 23:15:11 adrianp Exp $

DISTNAME=	imp-h3-${IMPVER}
PKGNAME=	imp-${IMPVER}
PKGREVISION=	1
CATEGORIES=	mail www
MASTER_SITES=	http://ftp.horde.org/pub/imp/ \
		ftp://ftp.horde.org/pub/imp/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.horde.org/imp/
COMMENT=	Internet Messaging Program

CONFLICTS+=	imp-3.*

DEPENDS+=	horde>=3.0.2:../../www/horde
DEPENDS+=	${PHP_PKG_PREFIX}-imap>4.3.3:../../mail/php-imap
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Mail-[0-9]*:../../mail/pear-Mail

.include "../../mk/bsd.prefs.mk"

DOCDIR=		${PREFIX}/share/doc/imp
EGDIR=		${PREFIX}/share/examples/imp
HORDEDIR=	${PREFIX}/share/horde
IMPDIR=		${HORDEDIR}/imp
IMPVER=		4.1.5
PAXDIRS=	lib locale po scripts templates themes

PKG_USERS_VARS+=	APACHE_USER
BUILD_DEFS+=		APACHE_USER

MESSAGE_SUBST+=	IMPDIR=${IMPDIR:Q}
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

PKG_SYSCONFSUBDIR?=	httpd

CONF_FILES=		${EGDIR}/imp.conf ${PKG_SYSCONFDIR}/imp.conf
CONF_FILES+=		${IMPDIR}/config/servers.php.dist \
			${IMPDIR}/config/servers.php
CONF_FILES_PERMS+=	${IMPDIR}/config/conf.xml.dist \
			${IMPDIR}/config/conf.xml \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${IMPDIR}/config/filter.txt.dist \
			${IMPDIR}/config/filter.txt \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${IMPDIR}/config/header.php.dist \
			${IMPDIR}/config/header.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${IMPDIR}/config/menu.php.dist \
			${IMPDIR}/config/menu.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${IMPDIR}/config/mime_drivers.php.dist \
			${IMPDIR}/config/mime_drivers.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${IMPDIR}/config/motd.php.dist \
			${IMPDIR}/config/motd.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${IMPDIR}/config/prefs.php.dist \
			${IMPDIR}/config/prefs.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${IMPDIR}/config/trailer.txt.dist \
			${IMPDIR}/config/trailer.txt \
			${APACHE_USER} ${ROOT_GROUP} 0440

SUBST_CLASSES+=		files
SUBST_STAGE.files=	post-build
SUBST_FILES.files=	imp.conf.dist
SUBST_SED.files=	-e "s|@IMPDIR@|${IMPDIR}|g"
SUBST_MESSAGE.files=	Fixing configuration files.

.include "options.mk"

do-build:
	${CP} ${FILESDIR}/imp.conf.dist ${WRKSRC}/imp.conf.dist
	${CP} ${WRKSRC}/config/conf.xml ${WRKSRC}/config/conf.xml.dist
	${FIND} ${WRKSRC} -name .htaccess -print | ${XARGS} ${RM} -f

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${IMPDIR}
	${INSTALL_DATA_DIR} ${IMPDIR}/config
	${INSTALL_DATA} ${WRKSRC}/imp.conf.dist ${EGDIR}/imp.conf
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCDIR}

.	for d in ${PAXDIRS}
		${INSTALL_DATA_DIR} ${IMPDIR}/${d}
.	endfor

.	for d in ${PAXDIRS}
		cd ${WRKSRC}/${d} && ${PAX} -rwpam . ${IMPDIR}/${d}
.	endfor

	${INSTALL_DATA} ${WRKSRC}/config/*.dist ${IMPDIR}/config
	${INSTALL_DATA} ${WRKSRC}/*.php ${IMPDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${IMPDIR}
	${FIND} ${IMPDIR} -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${IMPDIR} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}
	${CHOWN} ${APACHE_USER}:${ROOT_GROUP} ${IMPDIR}/config
	${CHMOD} 0750 ${IMPDIR}/config

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
