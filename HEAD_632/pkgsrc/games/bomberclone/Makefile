# $NetBSD: Makefile,v 1.25 2007/07/08 09:45:47 wiz Exp $

DISTNAME=		bomberclone-0.11.7
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bomberclone/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.bomberclone.de/
COMMENT=		Multi-player Bomberman clone

CONFLICTS=		bomberclone-data-[0-9]*

BUILDLINK_TRANSFORM+=	rm:-Werror
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

post-install:
	${RM} -fr ${PREFIX}/share/bomberclone/*/CVS
	${RM} -fr ${PREFIX}/share/bomberclone/*/*/CVS
	${RM} -fr ${PREFIX}/share/bomberclone/*/*/*/CVS

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
