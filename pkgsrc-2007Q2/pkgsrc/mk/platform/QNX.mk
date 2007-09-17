# $NetBSD: NetBSD.mk,v 1.21 2006/07/20 20:02:23 jlam Exp $
#
# Variable definitions for the QNX operating system.

# Needed for 1.6.1 and earlier due to rpcgen bugs and paths
#.if defined(CPP) && ${CPP} == "cpp"
#CPP=		/usr/bin/cpp
#.endif

ECHO_N?=	${ECHO} -n
IMAKE_MAKE?=	${MAKE}		# program which gets invoked by imake
PKGLOCALEDIR?=	share
PS?=		/bin/ps
RSH?=		/usr/bin/rsh
SU?=		/bin/su
TYPE?=		type				# Shell builtin
TOUCH_FLAGS?=


CPP_PRECOMP_FLAGS?=	# unset
DEF_UMASK?=		0022
#EXPORT_SYMBOLS_LDFLAGS?=-Wl,-E	# add symbols to the dynamic symbol table
EXPORT_SYMBOLS_LDFLAGS?=	# Don't add symbols to the dynamic symbol table
MOTIF_TYPE_DEFAULT?=	openmotif	# default 2.0 compatible libs type
NOLOGIN?=		/bin/false
.if exists(${LOCALBASE}/sbin/pkg_info)
PKG_TOOLS_BIN?=		${LOCALBASE}/sbin
.else
PKG_TOOLS_BIN?=		/usr/sbin
.endif
ROOT_CMD?=		${SU} - root -c
ROOT_USER?=		root
ROOT_GROUP?=	root
ULIMIT_CMD_datasize?=	ulimit -d `ulimit -H -d`
ULIMIT_CMD_stacksize?=	ulimit -s `ulimit -H -s`
ULIMIT_CMD_memorysize?=	ulimit -m `ulimit -H -m`

# imake installs manpages in weird places
# these values from /usr/X11R6/lib/X11/config/NetBSD.cf
IMAKE_MAN_SOURCE_PATH=	man/cat
IMAKE_MANNEWSUFFIX=	0
IMAKE_MAN_SUFFIX=	${IMAKE_MANNEWSUFFIX}
IMAKE_LIBMAN_SUFFIX=	${IMAKE_MANNEWSUFFIX}
IMAKE_KERNMAN_SUFFIX=	${IMAKE_MANNEWSUFFIX}
IMAKE_FILEMAN_SUFFIX=	${IMAKE_MANNEWSUFFIX}
IMAKE_GAMEMAN_SUFFIX=	${IMAKE_MANNEWSUFFIX}
IMAKE_MISCMAN_SUFFIX=	${IMAKE_MANNEWSUFFIX}
IMAKE_MAN_DIR=		${IMAKE_MAN_SOURCE_PATH}1
IMAKE_LIBMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}3
IMAKE_KERNMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}4
IMAKE_FILEMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}5
IMAKE_GAMEMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}6
IMAKE_MISCMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}7
IMAKE_MANINSTALL?=	maninstall catinstall

.if exists(/usr/include/netinet6)
_OPSYS_HAS_INET6=	yes	# IPv6 is standard
.else
_OPSYS_HAS_INET6=	no	# IPv6 is not standard
.endif
_OPSYS_HAS_JAVA=	no	# Java is not standard
_OPSYS_HAS_MANZ=	no	# MANZ controls gzipping of man pages
_OPSYS_HAS_OSSAUDIO=	no	# libossaudio is available
_OPSYS_PERL_REQD=		# no base version of perl required
_OPSYS_PTHREAD_AUTO=	no	# -lpthread needed for pthreads
_OPSYS_SHLIB_TYPE=	ELF	# shared lib type
_PATCH_CAN_BACKUP=	yes	# native patch(1) can make backups
_PATCH_BACKUP_ARG?=	-b -V simple -z 	# switch to patch(1) for backup suffix
_USE_RPATH=		yes	# add rpath to LDFLAGS

# flags passed to the linker to extract all symbols from static archives.
# this is GNU ld.
_OPSYS_WHOLE_ARCHIVE_FLAG=	-Wl,--whole-archive
_OPSYS_NO_WHOLE_ARCHIVE_FLAG=	-Wl,--no-whole-archive

_STRIPFLAG_CC?=		${_INSTALL_UNSTRIPPED:D:U-s}	# cc(1) option to strip
_STRIPFLAG_INSTALL?=	${_INSTALL_UNSTRIPPED:D:U-s}	# install(1) option to strip

DEFAULT_SERIAL_DEVICE?=	/dev/ser1
SERIAL_DEVICES?=	/dev/ser1 \
			/dev/ser2

# check for kqueue(2) support, added in NetBSD-1.6J
#.if exists(/usr/include/sys/event.h)
#PKG_HAVE_KQUEUE=	# defined
#.endif

# check for maximum command line length and set it in configure's environment,
# to avoid a test required by the libtool script that takes forever.
#_OPSYS_MAX_CMDLEN_CMD=	/sbin/sysctl -n kern.argmax
