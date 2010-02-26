/*
 * i386/qnx6/jit-md.h
 * Qnx i3866 JIT configuration information.
 *
 * Copyright (c) 1996, 1997
 *	Transvirtual Technologies, Inc.  All rights reserved.
 *
 * See the file "license.terms" for information on usage and redistribution 
 * of this file. 
 */

#ifndef __i386_qnx6_jit_md_h
#define __i386_qnx6_jit_md_h

/**/
/* Include common information. */
/**/
#include "i386/jit.h"

/**/
/* Extra exception handling information. */
/**/

/* Function prototype for signal handlers */
#define	EXCEPTIONPROTO SIGNAL_ARGS(sig, ctx)

/* Get the first exception frame from a signal handler */
#define	EXCEPTIONFRAME(f, c)						\
        (f).retbp = ((ucontext_t *)(c))->uc_mcontext.cpu.ebp; \
	(f).retpc = 1 + _UC_MACHINE_PC(((ucontext_t *)(c)))

#endif
