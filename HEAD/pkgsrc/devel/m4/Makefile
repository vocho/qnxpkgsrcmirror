# $NetBSD: Makefile,v 1.51 2007/07/29 14:36:46 joerg Exp $

DISTNAME=	m4-1.4.10
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=m4/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://directory.fsf.org/gnum4.html
COMMENT=	GNU version of UNIX m4 macro language processor

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
INFO_FILES=		yes
#LICENSE=		GPLv3

TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS+=	--program-prefix=${GNU_PROGRAM_PREFIX:Q}
.endif
PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX:Q}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

.if !defined(GNU_PROGRAM_PREFIX) || ${GNU_PROGRAM_PREFIX} != "g"
PLIST_SUBST+=		GM4_LINK=""
.else
PLIST_SUBST+=		GM4_LINK="@comment "
.endif

.if ${OPSYS} == "DragonFly"
post-patch:
	${CP} ${FILESDIR}/bsd-fflush.c ${WRKSRC}/lib/fflush.c
.elif ${OPSYS} == "QNX"
# For now.
#
# Our fflush() happens to work the way m4 expects so their
# replacement rpl_fflush() isn't brought in and therefore
# their non-portable gnulib fpurge() and freading() aren't
# needed.  The correct fix is for autoconf to remove all
# references to fpurge() and freading() (including from the
# tests) if fflush() works as expected.
post-patch:
	${CP} ${FILESDIR}/qnx-fpurge.c ${WRKSRC}/lib/fpurge.c
	${CP} ${FILESDIR}/qnx-freading.c ${WRKSRC}/lib/freading.c
.endif

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/m4
	${INSTALL_DATA} ${WRKSRC}/examples/*.m4 ${DESTDIR}${PREFIX}/share/examples/m4
.if !defined(GNU_PROGRAM_PREFIX) || ${GNU_PROGRAM_PREFIX} != "g"
	${LN} -sf ${GNU_PROGRAM_PREFIX}m4 ${DESTDIR}${PREFIX}/bin/gm4
.endif

.include "../../mk/bsd.pkg.mk"
