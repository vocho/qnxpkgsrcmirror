# $NetBSD: Makefile,v 1.16 2007/05/20 15:49:29 taca Exp $

DISTNAME=	Mule-UCS-0.84
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	5
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/Mule-UCS/

MAINTAINER=	uebayasi@NetBSD.org
#HOMEPAGE=
COMMENT=	Another encoding conversion mechanism for Emacs

# Mule 4.1 feature required by Mule-UCS was added to 20.7nb1.
EMACS_VERSIONS_ACCEPTED=	emacs21 emacs21nox emacs20
BUILDLINK_API_DEPENDS.emacs20+=	emacs>=20.7nb1

MESSAGE_SUBST+=	EMACS_LISPPREFIX=${EMACS_LISPPREFIX:Q}

do-build:
	@cd ${WRKSRC}; \
	${EMACS_BIN} -q --no-site-file -batch -l mucs-comp.el
	@cd ${WRKSRC}/lisp/big5conv; \
	${EMACS_BIN} -q --no-site-file -batch -l big5-comp.el
	@cd ${WRKSRC}/lisp/jisx0213; \
	${EMACS_BIN} -q --no-site-file -batch -l x0213-comp.el

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/mule-ucs
	cd ${WRKSRC}/lisp && \
	for f in ChangeLog README* *.txt *.el *.elc *.txt; do \
		${INSTALL_DATA} $$f ${EMACS_LISPPREFIX}/mule-ucs; \
	done
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/mule-ucs/big5conv
	${INSTALL_DATA} ${WRKSRC}/lisp/big5conv/* \
	    ${EMACS_LISPPREFIX}/mule-ucs/big5conv; \
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/mule-ucs/jisx0213
	${INSTALL_DATA} ${WRKSRC}/lisp/jisx0213/* \
	    ${EMACS_LISPPREFIX}/mule-ucs/jisx0213; \
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/mule-ucs/reldata
	${INSTALL_DATA} ${WRKSRC}/lisp/reldata/* \
	    ${EMACS_LISPPREFIX}/mule-ucs/reldata

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
