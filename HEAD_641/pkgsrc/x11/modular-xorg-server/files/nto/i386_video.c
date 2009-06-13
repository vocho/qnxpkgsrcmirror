/*
 * Copyright 1992 by Rich Murphey <Rich@Rice.edu>
 * Copyright 1993 by David Wexelblat <dwex@goblin.org>
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the names of Rich Murphey and David Wexelblat 
 * not be used in advertising or publicity pertaining to distribution of 
 * the software without specific, written prior permission.  Rich Murphey and
 * David Wexelblat make no representations about the suitability of this 
 * software for any purpose.  It is provided "as is" without express or 
 * implied warranty.
 *
 * RICH MURPHEY AND DAVID WEXELBLAT DISCLAIM ALL WARRANTIES WITH REGARD TO 
 * THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND 
 * FITNESS, IN NO EVENT SHALL RICH MURPHEY OR DAVID WEXELBLAT BE LIABLE FOR 
 * ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER 
 * RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF 
 * CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN 
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 */

#ifdef HAVE_XORG_CONFIG_H
#include <xorg-config.h>
#endif

#include <X11/X.h>
#include "xf86.h"
#include "xf86Priv.h"

#include <errno.h>
#include <sys/mman.h>

#include "xf86_OSlib.h"
#include "xf86OSpriv.h"

#include <sys/neutrino.h>

/***************************************************************************/
/* Video Memory Mapping section                                            */
/***************************************************************************/
static pointer mapVidMem(int, unsigned long, unsigned long, int);
static void unmapVidMem(int, pointer, unsigned long);


void
xf86OSInitVidMem(VidMemInfoPtr pVidMem)
{
	pVidMem->linearSupported = TRUE;
	pVidMem->mapMem = mapVidMem;
	pVidMem->unmapMem = unmapVidMem;
	pVidMem->initialised = TRUE;
}

static pointer
mapVidMem(int ScreenNum, unsigned long Base, unsigned long Size, int flags)
{
	pointer base;

	base = mmap_device_memory (0, Size, (flags & VIDMEM_READONLY) ? 
							   PROT_READ : (PROT_READ | PROT_WRITE), 0, (uint64_t)Base);
	if (base == MAP_FAILED)
	{
		FatalError("%s: could not mmap %s [s=%lx,a=%lx] (%s)",
				   "xf86MapVidMem", DEV_MEM, Size, Base, 
				   strerror(errno));
	}
	return(base);
}

static void
unmapVidMem(int ScreenNum, pointer Base, unsigned long Size)
{
	munmap_device_memory((caddr_t)Base, Size);
}

/*
 * Read BIOS via mmap()ing DEV_MEM
 */

_X_EXPORT int
xf86ReadBIOS(unsigned long Base, unsigned long Offset, unsigned char *Buf,
			 int Len)
{
	unsigned char *ptr;
	int psize;
	int mlen;

	psize = xf86getpagesize();
	Offset += Base & (psize - 1);
	Base &= ~(psize - 1);
	mlen = (Offset + Len + psize - 1) & ~(psize - 1);
	ptr = (unsigned char *)mmap_device_memory((caddr_t)0, mlen, PROT_READ,
					0, (off_t)Base);
	if ((long)ptr == -1)
	{
		xf86Msg(X_WARNING, 
				"xf86ReadBIOS: %s mmap[s=%x,a=%lx,o=%lx] failed (%s)\n",
				DEV_MEM, Len, Base, Offset, strerror(errno));
		return(-1);
	}
#ifdef DEBUG
	ErrorF("xf86ReadBIOS: BIOS at 0x%08x has signature 0x%04x\n",
		Base, ptr[0] | (ptr[1] << 8));
#endif
	(void)memcpy(Buf, (void *)(ptr + Offset), Len);
	(void)munmap_device_memory((caddr_t)ptr, mlen);
#ifdef DEBUG
	xf86MsgVerb(X_INFO, 3, "xf86ReadBIOS(%x, %x, Buf, %x)"
		"-> %02x %02x %02x %02x...\n",
		Base, Offset, Len, Buf[0], Buf[1], Buf[2], Buf[3]);
#endif
	return(Len);
}

/***************************************************************************/
/* I/O Permissions section                                                 */
/***************************************************************************/

static Bool ExtendedEnabled = FALSE;

_X_EXPORT Bool
xf86EnableIO()
{
	if (ExtendedEnabled)
		return TRUE;

	if (ThreadCtl(_NTO_TCTL_IO, 0) < 0)
	{
		xf86Msg(X_WARNING,"%s: Failed to gain I/O privileges: %d\n", 
			   "xf86EnableIO", errno);
		return FALSE;
	}
	ExtendedEnabled = TRUE;

	return TRUE;
}
	
_X_EXPORT void
xf86DisableIO()
{
	// on nto, once enabled, never disable...
	return;
}

/***************************************************************************/
/* Interrupt Handling section                                              */
/***************************************************************************/

_X_EXPORT Bool
xf86DisableInterrupts()
{

	InterruptDisable();
	return(TRUE);
}

_X_EXPORT void
xf86EnableInterrupts()
{
	InterruptEnable();
	return;
}

