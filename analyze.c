#include <stdint.h>
#include <stdlib.h>

#include <time.h>

#include "analyze.h"
#include "algorithm.h"


Measurement benchmark(const Algorithm algorithm, const size_t iterations)
{
	clock_t exe_time;
	//double time_taken;

	//Start timer
	exe_time = clock();
	//algorithm goes here

	//end timer
	exe_time = clock() - exe_time;
	//time_taken = ((double)exe_time) / CLOCKS_PER_SEC;

	return (Measurement) { .size = 0, .time = 0.0 };

}

void random(int array[], const size_t lenght)
{
	srand(1337);

	for (int index = 0; index < lenght; index++)
	{
		array[index] = rand();
	}
}

