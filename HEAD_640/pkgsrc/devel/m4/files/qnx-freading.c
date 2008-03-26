#include "freading.h"
#include <stdio.h>
#include <stdlib.h>

bool
freading (FILE *fp)
{
	fprintf(stderr, "Under QNX fflush() behaves as m4 expects;\n"
	    "therefore, freading() should only be used by the tests.\n"
	    "If that's the case here, sure it's a failure but so what.\n");
	abort();
	return 0;
}
