# $NetBSD: Makefile,v 1.4 2008/07/16 20:56:00 abs Exp $
#

DISTNAME=		postgresql-jdbc-8.2-${PGBUILD}.src
PKGNAME=		jdbc-postgresql82-${PGBUILD}
DISTFILES+=		${DISTNAME}.tar.gz ${JARDIST}
CATEGORIES=		databases
MASTER_SITES=		http://jdbc.postgresql.org/download/

MAINTAINER=		abs@NetBSD.org
HOMEPAGE=		http://jdbc.postgresql.org/
COMMENT=		PostgreSQL 8.2 JDBC3 driver

PGBUILD=		508
JARDIST=		postgresql-8.2-${PGBUILD}.jdbc3.jar
JARFILE=		postgresql82.jar
EXTRACT_ONLY=           ${DISTFILES:N*.jar}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_JAVA=		run
USE_JAVA2=		1.4
NO_BUILD=       	YES

DOCDIR=                 share/doc/java/${PKGBASE}
PLIST_SUBST+=		JARFILE=${JARFILE:Q}
PLIST_SUBST+=		DOCDIR=${DOCDIR:Q}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/java
	${INSTALL_DATA} ${DISTDIR}/${JARDIST} \
		${DESTDIR}${PREFIX}/lib/java/${JARFILE}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
