# $NetBSD: Makefile,v 1.33 2008/11/08 17:36:36 jwise Exp $

DISTNAME=	Cocoon-1.8.2
PKGNAME=	cocoon-1.8.2
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://cocoon.apache.org/dist/cocoon/cocoon1/

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://cocoon.apache.org/
COMMENT=	The Apache Project's XML/XSL based web publishing system

BROKEN_IN=		pkgsrc-2006Q1 pkgsrc-2006Q4

BROKEN=		This needs update to a newer version which can be built \
against recent JDK and Servlet API versions.

# These are exact version requirements intentionally, and will need to remain
# so until the interfaces stabilize more.  Until then, new versions of these
# libraries will be tested heavily with cocoon, and if not usable will be
# imported as -current packages.
#
DEPENDS+=	xalan-j-1.2:../../textproc/xalan-j
DEPENDS+=	fop-0.15.0{,nb[0-9]*}:../../textproc/fop
DEPENDS+=	jakarta-servletapi-[0-9]*:../../www/jakarta-servletapi

# In addition to the above requirements, cocoon will build in support for the
# following if they are in ${CLASSPATH}
#
# org.apache.cocoon.transformer.XTTransformer ===> pkgsrc/textproc/xt
#
# org.apache.cocoon.processor.ldap.LdapProcessor ===>
#	Sun JNDI API 1.2.1+ (http://java.sun.com/products/jndi/index.html)
#
# org.apache.cocoon.processor.dcp.DCPProcessor ===>
#	FESI 1.21+ (http://home.worldcom.ch/jmlugrin/fesi/download.html)

NO_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_TOOLS+=	pax

post-extract:
	${RM} ${WRKSRC}/lib/fop_0_15_0.jar ${WRKSRC}/lib/servlet_2_2.jar \
		${WRKSRC}/lib/xalan_1_2_D02.jar ${WRKSRC}/lib/xerces_1_2.jar \
		${WRKSRC}/lib/bsf.jar ${WRKSRC}/lib/bsfengines.jar \
		${WRKSRC}/lib/xml.jar ${WRKSRC}/lib/xt.jar \
		${WRKSRC}/lib/fesi.jar

# note that we can't rebuild the javadoc documentation, and have to use that
# which it shipped with, as the javadoc target requires StyleBook, which uses
# features of JDK 1.2

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} build.sh

# For now, we install the turbine-pool.jar which ships with cocoon.  When there is an actual
# release of Turbine, we will have a package for it, which cocoon will depend on.
do-install:
	${INSTALL_DATA} ${WRKSRC}/bin/cocoon.jar ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/lib/turbine-pool.jar ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/lib/sax-bugfix.jar ${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/cocoon
	cd ${WRKSRC}/docs && pax -rw -pp . ${PREFIX}/share/doc/java/cocoon
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/java/cocoon/WEB-INF
	${INSTALL_DATA} ${FILESDIR}/web.xml ${PREFIX}/share/examples/java/cocoon/WEB-INF
	${INSTALL_DATA} ${WRKSRC}/conf/cocoon.properties ${PREFIX}/share/examples/java/cocoon/WEB-INF
	cd ${WRKSRC}/samples && pax -rw -pp . ${PREFIX}/share/examples/java/cocoon

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"

CLASSPATH:=${CLASSPATH}:${LOCALBASE}/lib/java/fop.jar:${LOCALBASE}/lib/java/xalan.jar:${LOCALBASE}/lib/java/bsf.jar:${LOCALBASE}/lib/java/xerces.jar:${LOCALBASE}/lib/java/servlet.jar:${PKG_JAVA_HOME}/lib/classes.zip:${PKG_JAVA_HOME}/lib/tools.jar
MAKE_ENV+=	CLASSPATH=${CLASSPATH:Q}
