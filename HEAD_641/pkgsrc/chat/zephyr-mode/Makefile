# $NetBSD: Makefile,v 1.16 2009/08/06 01:44:47 minskim Exp $
#

DISTNAME=	zephyr-mode-2.5.20
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	3
CATEGORIES=	chat net
MASTER_SITES=	http://www.cs.cmu.edu/People/dkindred/zephyr-mode/

MAINTAINER=	sommerfeld@NetBSD.org
HOMEPAGE=	http://www.cs.cmu.edu/People/dkindred/zephyr/zephyr.html
COMMENT=	CMU Emacs-based Zephyr client

DEPENDS+=	tzc>=2.6.15:../../chat/tzc

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes

.include "../../editors/emacs/modules.mk"

do-install:
	@${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}/zephyr-mode
	@for f in ${WRKSRC}/elisp/*.el; do \
		j="${INSTALL_DATA} $$f ${DESTDIR}${EMACS_LISPPREFIX}/zephyr-mode"; \
		${ECHO} $$j; $$j; \
	done

.include "../../mk/bsd.pkg.mk"
