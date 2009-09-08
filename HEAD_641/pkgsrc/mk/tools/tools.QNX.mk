#
# System-supplied tools for the QNX operating system.

TOOLS_PLATFORM.[?=		[			# shell builtin
TOOLS_PLATFORM.awk?=		/usr/bin/awk
TOOLS_PLATFORM.basename?=	/usr/bin/basename
.if exists(${QNX_HOST}/usr/bin/bison)
TOOLS_PLATFORM.bison?=          ${QNX_HOST}/usr/bin/bison
TOOLS_PLATFORM.bison-yacc?=     ${QNX_HOST}/usr/bin/bison -y
.endif
.if exists(/usr/bin/bzcat)
TOOLS_PLATFORM.bzcat?=		/usr/bin/bzcat
.endif
TOOLS_PLATFORM.cat?=		/bin/cat
TOOLS_PLATFORM.chgrp?=		/bin/chgrp
TOOLS_PLATFORM.chmod?=		/bin/chmod
TOOLS_PLATFORM.chown?=		/bin/chown
TOOLS_PLATFORM.cmp?=		/usr/bin/cmp
TOOLS_PLATFORM.cp?=		/bin/cp
TOOLS_PLATFORM.cut?=		/usr/bin/cut
TOOLS_PLATFORM.date?=		/usr/bin/date
TOOLS_PLATFORM.diff?=		/usr/bin/diff
TOOLS_PLATFORM.diff3?=		/usr/bin/diff3
TOOLS_PLATFORM.dirname?=	/usr/bin/dirname
TOOLS_PLATFORM.echo?=		echo			# shell builtin
TOOLS_PLATFORM.egrep?=		/usr/bin/egrep
TOOLS_PLATFORM.env?=		/usr/bin/env
TOOLS_PLATFORM.expr?=		/usr/bin/expr
TOOLS_PLATFORM.false?=		false			# shell builtin
TOOLS_PLATFORM.fgrep?=		/usr/bin/fgrep
TOOLS_PLATFORM.file?=		/usr/bin/file
TOOLS_PLATFORM.find?=		/usr/bin/find
TOOLS_PLATFORM.flex?=		${QNX_HOST}/usr/bin/flex
TOOLS_PLATFORM.ftp?=		/usr/bin/ftp
TOOLS_PLATFORM.gawk?=		/usr/bin/gawk
TOOLS_PLATFORM.grep?=		/usr/bin/grep
.if exists(${QNX_HOST}/usr/bin/groff)
TOOLS_PLATFORM.groff?=		${QNX_HOST}/usr/bin/groff
.endif
TOOLS_PLATFORM.gunzip?=		/bin/gunzip -f
TOOLS_PLATFORM.gzcat?=		/bin/gzip -dc
TOOLS_PLATFORM.gzip?=		/bin/gzip -nf ${GZIP}
TOOLS_PLATFORM.head?=		/usr/bin/head
TOOLS_PLATFORM.hostname?=	/bin/hostname
TOOLS_PLATFORM.id?=		/usr/bin/id
.if exists(/sbin/ldconfig)
TOOLS_PLATFORM.ldconfig?=	/sbin/ldconfig
.endif
TOOLS_PLATFORM.ksh?=		/bin/ksh
.if exists(${QNX_HOST}/usr/bin/lex)
TOOLS_PLATFORM.lex?=		${QNX_HOST}/usr/bin/lex
.endif
TOOLS_PLATFORM.ln?=		/bin/ln
TOOLS_PLATFORM.ls?=		/bin/ls
.if exists(/usr/bin/m4)
TOOLS_PLATFORM.m4?=		/usr/bin/m4
.endif
.if exists(/usr/bin/mail)
TOOLS_PLATFORM.mail?=		/usr/bin/mail
.endif
TOOLS_PLATFORM.gmake?=           ${QNX_HOST}/usr/bin/make
.if exists(/usr/bin/makeinfo)
TOOLS_PLATFORM.makeinfo?=	/usr/bin/makeinfo
.endif
TOOLS_PLATFORM.mkdir?=		/bin/mkdir -p
.if exists(/usr/bin/mktemp)
TOOLS_PLATFORM.mktemp?=		/usr/bin/mktemp
.endif
.if exists(/usr/bin/msgfmt)
TOOLS_PLATFORM.msgfmt?=		/usr/bin/msgfmt
.endif
.if exists(/usr/sbin/mtree)
TOOLS_PLATFORM.mtree?=		/usr/sbin/mtree
.endif
TOOLS_PLATFORM.mv?=		/bin/mv
TOOLS_PLATFORM.nice?=		/usr/bin/nice
.if exists(${QNX_HOST}/usr/bin/nroff)
TOOLS_PLATFORM.nroff?=		${QNX_HOST}/usr/bin/nroff
.endif
.if exists(/usr/bin/openssl)
TOOLS_PLATFORM.openssl?=	/usr/bin/openssl
.endif
TOOLS_PLATFORM.patch?=		/usr/bin/patch
TOOLS_PLATFORM.printf?=		/usr/bin/printf
TOOLS_PLATFORM.pwd?=		/bin/pwd
TOOLS_PLATFORM.readelf?=	${QNX_HOST}/usr/bin/readelf
TOOLS_PLATFORM.rm?=		/bin/rm
TOOLS_PLATFORM.rmdir?=		/usr/bin/rmdir
.if exists(/usr/bin/sdiff)
TOOLS_PLATFORM.sdiff?=		/usr/bin/sdiff
.endif
TOOLS_PLATFORM.sed?=		/usr/bin/sed
TOOLS_PLATFORM.sh?=		/bin/sh
.if exists(/usr/bin/shlock)
TOOLS_PLATFORM.shlock?=		/usr/bin/shlock
.endif
TOOLS_PLATFORM.sleep?=		/usr/bin/sleep
.if exists(${QNX_HOST}/usr/bin/soelim)
TOOLS_PLATFORM.soelim?=		${QNX_HOST}/usr/bin/soelim
.endif
TOOLS_PLATFORM.sort?=		/usr/bin/sort
.if exists(${QNX_HOST}/usr/bin/strip)
TOOLS_PLATFORM.strip?=		${QNX_HOST}/usr/bin/strip
.endif
TOOLS_PLATFORM.tail?=		/usr/bin/tail
TOOLS_PLATFORM.tar?=		/usr/bin/tar
.if exists(${QNX_HOST}/usr/bin/tbl)
TOOLS_PLATFORM.tbl?=		${QNX_HOST}/usr/bin/tbl
.endif
TOOLS_PLATFORM.tee?=		/usr/bin/tee
TOOLS_PLATFORM.test?=		test			# shell builtin
TOOLS_PLATFORM.touch?=		/usr/bin/touch
TOOLS_PLATFORM.tr?=		/usr/bin/tr
TOOLS_PLATFORM.true?=		true			# shell builtin
.if exists(/usr/bin/tsort)
TOOLS_PLATFORM.tsort?=		/usr/bin/tsort
.endif
TOOLS_PLATFORM.wc?=		/usr/bin/wc
TOOLS_PLATFORM.xargs?=		/usr/bin/xargs
.if exists(/usr/bin/xgettext)
TOOLS_PLATFORM.xgettext?=	/usr/bin/xgettext
.endif
.if exists(/usr/bin/yacc)
TOOLS_PLATFORM.yacc?=		/usr/bin/yacc
.endif
