/*	$NetBSD: dumptar.c,v 1.1 2004/08/21 03:28:56 jlam Exp $	*/

/*-
 * Copyright (c) 2004 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Christos Zoulas.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *        This product includes software developed by the NetBSD
 *        Foundation, Inc. and its contributors.
 * 4. Neither the name of The NetBSD Foundation nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#if HAVE_CONFIG_H
#include "config.h"
#endif
#include <nbcompat.h>
#if HAVE_STDIO_H
#include <stdio.h>
#endif
#if HAVE_ERR_H
#include <err.h>
#endif
#if HAVE_FCNTL_H
#include <fcntl.h>
#endif
#if HAVE_SYS_STAT_H
#include <sys/stat.h>
#endif
#if HAVE_SYS_MMAN_H
#include <sys/mman.h>
#endif

#include "tar.h"

#define ussum(a) 1

static char *
buf(const char *p, size_t s)
{
	static char buf[1024];
	(void)snprintf(buf, sizeof(buf), "%s", p);
	buf[s] = '\0';
	return buf;
}

int
intarg(const char *p, size_t s)
{
	char *ep, *b = buf(p, s);
	int r = (int)strtol(p, &ep, 8);
	return r;
}

static int
usdump(void *p)
{
	HD_USTAR *t = p;
	int size = intarg(t->size, sizeof(t->size));
	size = ((size + 511) / 512) * 512 + 512;

	(void)fprintf(stdout, "*****\n");
#define PR(a) \
	(void)fprintf(stdout, #a "=%s\n", buf(t->a, sizeof(t->a)));
#define IPR(a) \
	(void)fprintf(stdout, #a "=%d\n", intarg(t->a, sizeof(t->a)));
#define OPR(a) \
	(void)fprintf(stdout, #a "=%o\n", intarg(t->a, sizeof(t->a)));
	PR(name);
	OPR(mode);
	IPR(uid);
	IPR(gid);
	IPR(size);
	OPR(mtime);
	OPR(chksum);
	(void)fprintf(stdout, "typeflag=%c\n", t->typeflag);
	PR(linkname);
	PR(magic);
	PR(version);
	PR(uname);
	PR(gname);
	OPR(devmajor);
	OPR(devminor);
	PR(prefix);
	return size;
}

int
main(int argc, char *argv[])
{
	int fd;
	struct stat st;
	char *p, *ep;

	if (argc != 2) {
		(void)fprintf(stderr, "Usage: %s <filename>\n", getprogname());
		return 1;
	}

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		err(1, "Cannot open `%s'", argv[1]);

	if (fstat(fd, &st) == -1)
		err(1, "Cannot fstat `%s'", argv[1]);

	if ((p = mmap(NULL, (size_t)st.st_size, PROT_READ,
	    MAP_FILE|MAP_PRIVATE, fd, (off_t)0)) == MAP_FAILED)
		err(1, "Cannot mmap `%s'", argv[1]);
	(void)close(fd);

	ep = (char *)p + (size_t)st.st_size;

	for (; p < ep + sizeof(HD_USTAR);) {
		if (ussum(p))
			p += usdump(p);
	}
	return 0;
}
