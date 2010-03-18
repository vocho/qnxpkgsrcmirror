/*
 * i386/qnx6/md.h
 * QNX6 i386 configuration information.
 *
 * Copyright (c) 1996, 1997
 *	Transvirtual Technologies, Inc.  All rights reserved.
 *
 * Copyright (c) 2003
 *      Kaffe.org contributors. See ChangeLog for details.
 *
 * See the file "license.terms" for information on usage and redistribution 
 * of this file. 
 */

#ifndef __i386_qnx6_md_h
#define __i386_qnx6_md_h


#include "i386/common.h"
#include "i386/threads.h"

#if defined(HAVE_SIGNAL_H)
#include <signal.h>
#endif
#if defined(HAVE_SYS_RESOURCE_H)
#include <sys/resource.h>
#endif
#if defined(HAVE_SYS_SIGNAL_H)
#include <sys/signal.h>
#endif
#if defined(HAVE_UNISTD_H)
#include <unistd.h>
#endif


#include <ucontext.h>
#ifndef _UC_MACHINE_SP
#define _UC_MACHINE_SP(uc)      ((uc))->uc_mcontext.cpu.esp
#endif
#ifndef _UC_MACHINE_PC
#define _UC_MACHINE_PC(uc)      ((uc))->uc_mcontext.cpu.eip
#endif
#define SIGCONTEXT ucontext_t

#define SIGNAL_ARGS(sig, sc) int sig, siginfo_t *__si, void *sc
#define SIGNAL_CONTEXT_POINTER(scp) SIGCONTEXT *scp

#if defined(TRANSLATOR)
#include "jit-md.h"
#endif


#include "kaffe-unix-stack.h"

#endif
