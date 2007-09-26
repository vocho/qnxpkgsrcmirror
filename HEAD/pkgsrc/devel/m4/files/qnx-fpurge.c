#include "fpurge.h"
#include <stdio.h>
#include <stdlib.h>

int
fpurge (FILE *fp)
{
	fprintf(stderr, "Under QNX fflush() behaves as m4 expects;\n"
	    "therefore, fpurge() should only be used by the tests.\n"
	    "If that's the case here, sure it's a failure but so what.\n");
	abort();
}
