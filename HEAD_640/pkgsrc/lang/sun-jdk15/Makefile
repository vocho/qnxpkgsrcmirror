# $NetBSD: Makefile,v 1.32 2008/08/15 15:06:36 he Exp $

DISTNAME=	jdk-1_5_0_16-linux-${DIST_ARCH}
PKGNAME=	sun-jdk15-5.0.16
MASTER_SITES=	# empty

SHORT_NAME=	JDK

DEPENDS+=	${PKGNAME_NOREV:S/jdk/jre/}*:../../lang/sun-jre15

WRKSRC=		${WRKDIR}/${DISTNAME:S/-//:S/_/./:S/_/./:C/-linux-.*//}
JAVA_WRAPPERS=	appletviewer apt extcheck idlj jar jarsigner \
		javac javadoc javah javap jdb rmic serialver

LICENSE=	sun-jdk6-license

.include "../../lang/sun-jre15/Makefile.common"

# Remove parts that are in common with the JRE
#
post-extract:
	common=`${AWK} '/^#.*/ { next } /^$$/ { next } { print }' ${FILESDIR}/common`; \
	cd ${WRKSRC}; for i in $$common; do				\
		if [ -d $$i ]; then					\
			${RM} -rf $$i;					\
		else							\
			${RM} -f $$i;					\
		fi;							\
	done
	${LN} -sf . ${WRKSRC}/jre

.include "../../mk/bsd.pkg.mk"
