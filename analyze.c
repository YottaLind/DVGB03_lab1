#include "analyze.h"
#include "algorithm.h"

//Needs to be included to mesure time taken by function 
#include <time.h>

//
// Private
//

clock_t exe_time; 
double time_taken;

//
// Public
//
void benchmark(const algorithm_t a, const case_t c, result_t *buf, int n)
{
    //Start timer
	exe_time = clock();
	//algorithm goes here

	//end timer
	exe_time = clock() - exe_time;
	time_taken = ((double)exe_time)/CLOCKS_PER_SEC;

}
