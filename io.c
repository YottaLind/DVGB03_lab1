#include "io.h"

#include <stdio.h>

char input()
{
	char result;
	if (scanf("%c%*c", &result)) { };

	return result;
}
