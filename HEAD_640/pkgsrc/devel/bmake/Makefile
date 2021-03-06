# $NetBSD: Makefile,v 1.46 2008/11/11 20:01:58 joerg Exp $
#

DISTNAME=	bmake-20081111
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

# distfile obtained from ftp://ftp.NetBSD.org/pub/NetBSD/misc/sjg/
# source is kept in files/ for bootstrap purposes

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.crufty.net/help/sjg/bmake.html
COMMENT=	Portable (autoconf) version of NetBSD 'make' utility

DEPENDS+=	bootstrap-mk-files-[0-9]*:../../pkgtools/bootstrap-mk-files

PKG_DESTDIR_SUPPORT=	user-destdir
BOOTSTRAP_PKG=	yes

WRKSRC=		${WRKDIR}/bmake
NO_CHECKSUM=	yes

USE_FEATURES=	nbcompat

makesyspath=	${PREFIX}/share/mk

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

BOOTSTRAP_ARGS=		-q -o ${OPSYS} --prefix=${PREFIX} \
			--with-default-sys-path=${makesyspath} \
			--mksrc none --sysconfdir=${PKG_SYSCONFDIR:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" || ${OPSYS} == "OSF1"
DEPENDS+=		pdksh-[0-9]*:../../shells/pdksh
BOOTSTRAP_ARGS+=	--with-defshell=${PREFIX}/bin/pdksh
.endif

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

do-configure:

do-build:
	cd ${WRKDIR} && \
		${SETENV} ${MAKE_ENV} ${SH} ./bmake/boot-strap ${BOOTSTRAP_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${OPSYS}/bmake ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bmake.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
