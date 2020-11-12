#include "analyze.h"
#include "algorithm.h"

//Needs to be included to mesure time taken by function
#include <time.h>

//For debuging, REMOVE after
#include <stdio.h>

void benchmark(const algorithm_t a, const case_t c, result_t *buf, int n)
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
