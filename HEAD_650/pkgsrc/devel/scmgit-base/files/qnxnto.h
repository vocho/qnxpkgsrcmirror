
#include <signal.h>

#ifndef SA_RESTART
#define SA_RESTART      0x0040

int sigaction_qnx(int, const struct sigaction *, struct sigaction *);

#define sigaction(a, b, c)	sigaction_qnx((a), (b), (c))
#endif
