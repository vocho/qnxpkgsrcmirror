# $NetBSD: Makefile,v 1.10 2007/07/29 05:20:00 jlam Exp $

DISTNAME=		opera-acroread7-1.0
PKGREVISION=		3

MAINTAINER=		jschauma@NetBSD.org
COMMENT=		Acrobat Reader 7 plugin for opera

DEPENDS+=		acroread7-7.[0-9]*:../../print/acroread7
CONFLICTS+=		opera-acroread-[0-9]*
CONFLICTS+=		opera-acroread3-[0-9]*
CONFLICTS+=		opera-acroread5-[0-9]*

ACROREAD=		Acrobat7
ACRO_SUBDIR=		Browser

.include "../../www/opera-acroread/Makefile.common"
.include "../../mk/bsd.pkg.mk"
