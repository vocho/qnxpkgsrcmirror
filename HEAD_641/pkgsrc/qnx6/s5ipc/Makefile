# 
#

DISTNAME=	s5ipc-0.1
CATEGORIES=	qnx6
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	xtang@qnx.com
HOMEPAGE=	# none
COMMENT=	Library and QNX Resource Manager to support SysV ipc

#PKG_INSTALLATION_TYPES=	overwrite pkgviews
#PKG_DESTDIR_SUPPORT=	user-destdir

NO_CHECKSUM=	yes
USE_LANGUAGES=	# none
AUTO_MKDIRS=	yes
USE_TOOLS+=	gmake

do-extract:
	mkdir -p ${WRKSRC} && cd ${FILESDIR}/s5ipc && cp -R * ${WRKSRC}/

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.pkg.mk"
