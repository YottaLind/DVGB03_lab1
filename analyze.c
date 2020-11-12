#include <stdlib.h>

#include <time.h>
#include <stdio.h>
#include "analyze.h"
#include "algorithm.h"


void benchmark(const Algorithm algorithm, const unsigned int iterations)
{
	clock_t clock_cycles;
	double time_taken;

	//Start timer
	clock_cycles = clock();
	//algorithm goes here
	for (int i = 0; i < 100000000; i++)
	{
		volatile int p = i;
		i = p;
	}
	//end timer
	clock_cycles = clock() - clock_cycles;
	time_taken = ((double)clock_cycles) / CLOCKS_PER_SEC;
	printf("TimeTaken: %f\n", time_taken);


}

void random_generate(int array[], const size_t lenght)
{
	srand(1337);

	for (int index = 0; index < lenght; index++)
	{
		array[index] = rand();
	}
}

