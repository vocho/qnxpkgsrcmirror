# $NetBSD: Makefile,v 1.10 2008/07/14 12:56:14 joerg Exp $

DISTNAME=	htdig-3.2.0b6
CATEGORIES=	www databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=htdig/} \
		http://www.htdig.org/files/ \
		http://www.it.htdig.org/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://htdig.sourceforge.net/
COMMENT=	WWW indexing and searching system

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-cgi-bin-dir=${PREFIX}/libexec/cgi-bin
CONFIGURE_ARGS+=	--with-common-dir=${PREFIX}/share/htdig/common
CONFIGURE_ARGS+=	--with-config-dir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-database-dir=${DBDIR:Q}
CONFIGURE_ARGS+=	--with-image-dir=${PREFIX}/share/examples/htdig
CONFIGURE_ARGS+=	--with-search-dir=${PREFIX}/share/examples/htdig
CONFIGURE_ENV+=		PDF_PARSER="${LOCALBASE}/bin/acroread"
CXXFLAGS+=		-Wno-deprecated

PKG_SYSCONFSUBDIR=	htdig

DBDIR?=		${VARBASE}/db/htdig
MESSAGE_SUBST+=	DBDIR=${DBDIR}
OWN_DIRS+=	${DBDIR}

CONF_FILES+=	${PREFIX}/share/examples/htdig/HtFileType-magic.mime \
		${PKG_SYSCONFDIR}/HtFileType-magic.mime
CONF_FILES+=	${PREFIX}/share/examples/htdig/cookies.txt \
		${PKG_SYSCONFDIR}/cookies.txt
CONF_FILES+=	${PREFIX}/share/examples/htdig/htdig.conf \
		${PKG_SYSCONFDIR}/htdig.conf
CONF_FILES+=	${PREFIX}/share/examples/htdig/mime.types \
		${PKG_SYSCONFDIR}/mime.types

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
