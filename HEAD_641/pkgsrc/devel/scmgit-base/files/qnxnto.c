#include "qnxnto.h"

#include <sys/neutrino.h>
#include <pthread.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>

void *
restart_thread(void *arg)
{
	for (;;)
		pause();
}

int
sigaction_qnx(int sig, const struct sigaction *act, struct sigaction *oact)
{
	static pthread_t	restart_tid;
	sigset_t		nset;
	int			ret;

	if (act->sa_flags & SA_RESTART) {
		if (restart_tid == 0 && (ret = pthread_create(&restart_tid,
		    NULL, restart_thread, NULL)) != EOK) {
			errno = ret;
			return -1;
		}

		/* Block in calling thread */
		sigemptyset(&nset);
		sigaddset(&nset, sig);
		pthread_sigmask(SIG_BLOCK, &nset, NULL);

		/* Make sure unblocked in restart thread if not already */
		SignalProcmask_r(0, restart_tid, SIG_UNBLOCK, &nset, NULL);
	}
	else {
		return sigaction(sig, act, oact);
	}
}
