# $NetBSD: Makefile,v 1.45 2013/07/15 02:02:22 ryoon Exp $

DISTNAME=		teg-0.11.1
PKGREVISION=		37
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=teg/}

MAINTAINER=		wrzymski@gmail.com
HOMEPAGE=		http://teg.sourceforge.net/
COMMENT=		Round-based computer board game

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		intltool msgfmt pkg-config

GCONF_SCHEMAS+=	teg.schemas

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
