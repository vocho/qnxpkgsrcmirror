# $NetBSD: Makefile,v 1.22 2008/06/20 01:09:23 joerg Exp $
#

DISTNAME=	sablevm-1.13
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://sablevm.org/download/release/1.13/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://sablevm.org/
COMMENT=	SableVM free Java virtual machine

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	unzip>=5.50:../../archivers/unzip
DEPENDS+=	sablevm-classpath-1.13nb1:../../lang/sablevm-classpath

GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${JAVA_HOME}
GNU_CONFIGURE_MANDIR=	${PREFIX}/${PKGMANDIR}
NO_MTREE=		yes
USE_TOOLS+=		gmake gm4
USE_LIBTOOL=		yes

JAVA_NAME=		sablevm
JAVA_HOME=		${PREFIX}/java/sablevm
JAVA_WRAPPERS+=		java
JAVA_WRAPPER_BIN.java=	${JAVA_HOME}/bin/java-sablevm --classpath $${CLASSPATH}

PRINT_PLIST_AWK+=     /^@dirrm java\/sablevm$$/ \
			|| /^@dirrm java\/sablevm\/share$$/ \
			|| /^@dirrm java\/sablevm\/include$$/ \
			|| /^@dirrm java\/sablevm\/lib$$/ \
			|| /^@dirrm java\/sablevm\/lib\/sablevm\/jre$$/ \
			|| /^@dirrm java\/sablevm\/lib\/sablevm$$/ \
			{ print "@comment in sablevm-classpath: " $$0; \
				next; }

BUILDLINK_PASSTHRU_RPATHDIRS+=	${JAVA_HOME}/lib

INSTALLATION_DIRS=	java/sablevm/lib/sablevm/bin java/sablevm/lib/sablevm/jre

.if !exists(/usr/include/semaphore.h)
LDFLAGS+=	-lsemaphore
BUILDLINK_TRANSFORM+=	l:rt:semaphore
.include "../../devel/pthread-sem/buildlink3.mk"
.endif
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/java-env.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
