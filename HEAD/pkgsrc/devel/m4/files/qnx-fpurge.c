#include "fpurge.h"
#include <stdio.h>
#include <stdlib.h>

int
fpurge (FILE *fp)
{
	fprintf(stderr, "fpurge\n");
	abort();
}
