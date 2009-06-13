# 
#

DISTNAME=	dupster-0.1
CATEGORIES=	qnx6
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	seanb@qnx.com
HOMEPAGE=	# none
COMMENT=	Resource Manager to redirect stdin/stdout/stderr

#PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

NO_CHECKSUM=	yes
#NO_BUILD=	yes
USE_LANGUAGES=	# none
#USE_TOOLS+=	perl:run
AUTO_MKDIRS=	yes
USE_TOOLS+=	gmake

do-extract:
	mkdir -p ${WRKSRC} && cd ${FILESDIR}/dupster && cp -R * ${WRKSRC}/

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.pkg.mk"
