# $NetBSD: Makefile,v 1.38 2009/05/28 21:06:46 wiz Exp $
#

DISTNAME=	evolution-exchange-2.26.2
EE_VER=		2.26
CATEGORIES=	mail gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/evolution-exchange/2.26/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.novell.com/products/desktop/features/evolution.html
COMMENT=	Support for Microsoft Exchange 2000 and 2003 in Evolution
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
PLIST_SUBST=		EE_VER=${EE_VER:Q}
GCONF_SCHEMAS=		apps_exchange_addressbook-${EE_VER}.schemas

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../mail/evolution/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
