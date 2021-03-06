# $NetBSD: Makefile,v 1.26 2007/11/13 02:40:06 cube Exp $

DISTNAME=		rt-3.4.6
CATEGORIES=		devel
MASTER_SITES=		http://download.bestpractical.com/pub/rt/release/

MAINTAINER=		cube@NetBSD.org
HOMEPAGE=		http://bestpractical.com/rt/
COMMENT=		Industrial-grade ticketing system

.include "options.mk"

USE_TOOLS+=	perl:run

# Core dependencies:
DEPENDS+=	p5-Digest-[0-9]*:../../security/p5-Digest
DEPENDS+=	p5-Digest-MD5>=2.27:../../security/p5-Digest-MD5
DEPENDS+=	p5-DBI>=1.37:../../databases/p5-DBI
DEPENDS+=	p5-Test-Inline>=0.15:../../devel/p5-Test-Inline
DEPENDS+=	p5-Class-ReturnValue>=0.40:../../devel/p5-Class-ReturnValue
DEPENDS+=	p5-DBIx-SearchBuilder>=1.35:../../databases/p5-DBIx-SearchBuilder
DEPENDS+=	p5-Text-Template>=1.43:../../textproc/p5-Text-Template
DEPENDS+=	p5-HTML-Parser>=3.35:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTML-Scrubber>=0.08:../../www/p5-HTML-Scrubber
DEPENDS+=	p5-Net>=1.15:../../net/p5-Net
DEPENDS+=	p5-Log-Dispatch>=2.0:../../devel/p5-Log-Dispatch
DEPENDS+=	p5-Locale-Maketext-Lexicon>=0.32:../../misc/p5-Locale-Maketext-Lexicon
DEPENDS+=	p5-Locale-Maketext-Fuzzy>=0.02:../../misc/p5-Locale-Maketext-Fuzzy
DEPENDS+=	p5-MIME-tools>=5.411.1:../../mail/p5-MIME-tools
DEPENDS+=	p5-MailTools>=1.57:../../mail/p5-MailTools
DEPENDS+=	p5-Text-Wrapper>=1.0:../../textproc/p5-Text-Wrapper
DEPENDS+=	p5-Time>=101.062101:../../time/p5-Time
DEPENDS+=	p5-Term-ReadKey>=2.21:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-Text-Autoformat>=1.04:../../textproc/p5-Text-Autoformat
DEPENDS+=	p5-Text-Quoted>=1.5:../../textproc/p5-Text-Quoted
DEPENDS+=	p5-Tree-Simple>=1.04:../../devel/p5-Tree-Simple
DEPENDS+=	p5-Module-Versions-Report-[0-9]*:../../devel/p5-Module-Versions-Report
DEPENDS+=	p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple
DEPENDS+=	p5-UNIVERSAL-require>=0.11:../../devel/p5-UNIVERSAL-require

# Mason dependencies:
DEPENDS+=	p5-Params-Validate>=0.02:../../devel/p5-Params-Validate
DEPENDS+=	p5-Cache-Cache>=1.02:../../devel/p5-Cache-Cache
DEPENDS+=	p5-Exception-Class>=1.14:../../devel/p5-Exception-Class
DEPENDS+=	p5-HTML-Mason>=1.31:../../www/p5-HTML-Mason
DEPENDS+=	p5-MLDBM>=2.01:../../databases/p5-MLDBM
DEPENDS+=	p5-FreezeThaw>=0.43:../../devel/p5-FreezeThaw
DEPENDS+=	p5-Storable>=2.08:../../devel/p5-Storable
DEPENDS+=	p5-Apache-Session>=1.53:../../www/p5-Apache-Session
DEPENDS+=	p5-XML-RSS>=1.05:../../textproc/p5-XML-RSS
DEPENDS+=	p5-HTTP-Server-Simple>=0.07:../../www/p5-HTTP-Server-Simple
DEPENDS+=	p5-HTTP-Server-Simple-Mason>=0.09:../../www/p5-HTTP-Server-Simple-Mason
DEPENDS+=	p5-Text-WikiFormat>=0.72:../../textproc/p5-Text-WikiFormat

# Mailgate dependencies:
DEPENDS+=	p5-HTML-Tree>=3.18:../../www/p5-HTML-Tree
DEPENDS+=	p5-HTML-Format>=2.03:../../www/p5-HTML-Format
DEPENDS+=	p5-libwww>=5.76:../../www/p5-libwww
DEPENDS+=	p5-Module-Refresh>=0.03:../../devel/p5-Module-Refresh

# Front-end dependencies:
.if !empty(PKG_OPTIONS:Mmodperl1)
DEPENDS+=	p5-libapreq>=1.2:../../www/p5-libapreq
DEPENDS+=	p5-Apache-DBI>=0.92:../../databases/p5-Apache-DBI
.elif !empty(PKG_OPTIONS:Mmodperl2)
DEPENDS+=	p5-Apache-DBI>=0.92:../../databases/p5-Apache-DBI
.elif !empty(PKG_OPTIONS:Mfastcgi)
DEPENDS+=	p5-FCGI>=0.67:../../www/p5-FCGI
.endif
.if !empty(PKG_OPTIONS:Mspeedycgi)
DEPENDS+=	SpeedyCGI-[0-9]*:../../www/SpeedyCGI
PLIST_SUBST+=	IF_SPEEDYCGI=""
.else
MAKE_FLAGS+=	RT_SPEEDYCGI_HANDLER=""
PLIST_SUBST+=	IF_SPEEDYCGI="@comment "

.PHONY: rm-speedycgi
post-install: rm-speedycgi
rm-speedycgi:
	rm -f ${PREFIX}/bin/mason_handler.scgi
.endif

# Back-end dependencies
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	p5-DBD-mysql>=2.1018:../../databases/p5-DBD-mysql
_RT_DB_TYPE=	mysql
.elif !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	p5-DBD-postgresql>=1.41:../../databases/p5-DBD-postgresql
_RT_DB_TYPE=	Pg
.elif !empty(PKG_OPTIONS:Moracle)
DEPENDS+=	p5-DBD-Oracle-[0-9]*:../../databases/p5-DBD-Oracle
_RT_DB_TYPE=	Oracle
.elif !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=	p5-DBD-SQLite-[0-9]*:../../databases/p5-DBD-SQLite
_RT_DB_TYPE=	SQLite
.endif

# Dev dependencies:
DEPENDS+=	p5-Regexp-Common>=2.113:../../textproc/p5-Regexp-Common
DEPENDS+=	p5-WWW-Mechanize>=0.72:../../www/p5-WWW-Mechanize
DEPENDS+=	p5-Test-WWW-Mechanize-[0-9]*:../../www/p5-Test-WWW-Mechanize

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
NO_BUILD=		yes
PKG_SYSCONFSUBDIR=	rt3

PKG_GROUPS=		${RT_GROUP}
PKG_GROUPS_VARS+=	RT_GROUP APACHE_GROUP
PKG_USERS_VARS+=	APACHE_USER

CONFIGURE_ARGS+=	--enable-layout=pkgsrc
CONFIGURE_ARGS+=	--with-rt-group=${RT_GROUP:Q}
CONFIGURE_ARGS+=	--with-db-type=${_RT_DB_TYPE:Q}
CONFIGURE_ARGS+=	--with-web-user=${APACHE_USER:Q}
CONFIGURE_ARGS+=	--with-web-group=${APACHE_GROUP:Q}
CONFIGURE_ARGS+=	--with-speedycgi=${PERL5_INSTALLVENDORBIN}/speedy
MESSAGE_SUBST+=		HOMEPAGE=${HOMEPAGE:Q}
MESSAGE_SUBST+=		RT_GROUP=${RT_GROUP:Q}
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

post-extract:
	cd ${WRKSRC} && chmod -R g-w .

.include "Makefile.install"

.include "../../mk/bsd.pkg.mk"
