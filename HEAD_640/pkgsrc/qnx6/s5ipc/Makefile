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
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
#NO_BUILD=	yes
USE_LANGUAGES=	# none
#USE_TOOLS+=	perl:run
AUTO_MKDIRS=	yes
USE_TOOLS+=	gmake

do-extract:
	cd ${FILESDIR} && cp -R * ${WRKSRC}/

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.pkg.mk"
