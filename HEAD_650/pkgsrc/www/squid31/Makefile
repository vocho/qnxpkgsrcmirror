# $NetBSD: Makefile,v 1.24 2010/08/04 11:36:08 tron Exp $

DISTNAME=	squid-3.1.6
PKGNAME=	${DISTNAME}	# Necessary for "pkgsrc/www/squid/options.mk"
CATEGORIES=	www
MASTER_SITES=	http://www.squid-cache.org/Versions/v3/3.1/ \
		${SQUID_MASTER_SITES}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.squid-cache.org/
COMMENT=	Post-Harvest_cached WWW proxy cache and accelerator
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		perl gmake
GNU_CONFIGURE=		yes

.include "../../www/squid/Makefile.squid"

CONFIGURE_ARGS+=	--with-default-user=${SQUID_USER}
CONFIGURE_ARGS+=	--with-pidfile=${VARBASE}/run/squid.pid

CFLAGS.QNX+=		-D__NO_EXT_QNX
LIBS.QNX+=		-ls5ipc

EGFILES+=     errors/errorpage.css
CONF_FILES+=  ${PREFIX}/${EGDIR}/errorpage.css ${PKG_SYSCONFDIR}/errorpage.css

SQUID_BACKENDS?=           ufs
SQUID_NTLM_AUTH_HELPERS?=  fakeauth
.include "../../www/squid/options.mk"

post-build:
	${CP} -pf ${WRKSRC}/src/squid.conf.documented \
	  ${WRKSRC}/src/squid.conf.default

.if ${OPSYS} == "QNX"
# Gack.  Maybe QNX8 will have a signed time_t
post-patch:
	${CP} ${FILESDIR}/qnx-inc.h ${WRKSRC}/compat/os
CFLAGS.QNX+=	-include ${WRKSRC}/compat/os/qnx-inc.h

.include "../../sysutils/s5ipc/buildlink3.mk"
.endif

.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
