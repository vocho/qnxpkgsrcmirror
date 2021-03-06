# $NetBSD: Makefile,v 1.3 2008/07/14 12:56:03 joerg Exp $
#

DISTNAME=		lyx-1.5.4
CATEGORIES=		editors
MASTER_SITES=		ftp://ftp.lyx.org/pub/lyx/stable/ \
			ftp://ftp.devel.lyx.org/pub/lyx/ \
			ftp://ftp.lip6.fr/pub/lyx/stable/ \
			http://sunsite.icm.edu.pl/pub/unix/editors/lyx/ \
			http://lyx.cybermirror.org/ \
			ftp://gd.tuwien.ac.at/publishing/tex/lyx/stable/ \
			ftp://ftp.sdsc.edu/pub/other/lyx/stable/ \
			http://lyx.mirror.fr/stable/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.lyx.org/
COMMENT=		Document processor and graphical frontend for LaTeX

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		lyx-qt-[0-9]*
CONFLICTS+=		lyx-xforms-[0-9]*
UNLIMIT_RESOURCES+=	datasize

USE_DIRS+=		texmf-1.0
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl:run
EXTRACT_USING=		gtar
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
TEX_ACCEPTED=		teTeX3
MAKE_ENV+=		PKG_LOCALTEXMFPREFIX=${PKG_LOCALTEXMFPREFIX}

CONFIGURE_ARGS+=	--with-qt4-dir=${QTDIR:Q}
CONFIGURE_ARGS+=	--with-qt4-includes=${BUILDLINK_PREFIX.qt4-libs}/qt4/include
CONFIGURE_ARGS+=	--with-qt4-libraries=${BUILDLINK_PREFIX.qt4-libs}/qt4/lib
CONFIGURE_ARGS+=	--with-pspell-lib=${BUILDLINK_PREFIX.aspell}/lib \
			--with-pspell-include=${BUILDLINK_PREFIX.aspell}/include/pspell \
			--with-pspell

PYTHON_PATCH_SCRIPTS=	lib/*.py \
			lib/doc/*.py \
			lib/lyx2lyx/*.py \
			lib/scripts/*.py lib/scripts/listerrors \
			po/*.py \
			development/tools/*.py \
			development/scons/*.py

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_FILES.python=	lib/configure.py
SUBST_FILES.python+=	lib/doc/Makefile.in
SUBST_SED.python=	-e "s,python ,${PYTHONBIN} ,"
SUBST_SED.python+=	-e "s,python -tt,${PYTHONBIN} -tt,g"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../print/teTeX/module.mk"
.include "../../textproc/aiksaurus/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
