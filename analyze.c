
#include "analyze.h"

#include "algorithm.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void populate(int array[], const size_t lenght)
{
	for (int index = 0; index < lenght; index++)
	{
		array[index] = rand();
	}
}

clock_t timing(const Algorithm algorithm, int array[], const size_t lenght)
{
	switch (algorithm)
	{
		case BubbleSort:
		{
			const clock_t start = clock();
			bubble_sort(array, lenght);

			return clock() - start;
		}

		case InsertionSort:
		{
			const clock_t start = clock();
			insertion_sort(array, lenght);

			return clock() - start;
		}

		case QuickSort:
		{
			const clock_t start = clock();
			quick_sort(array, lenght);

			return clock() - start;
		}

		case LinearSearch:
		{
			const clock_t start = clock();
			// bubble_sort(array, lenght);

			return clock() - start;
		}

		case BinarySearch:
		{
			quick_sort(array, lenght);

			const clock_t start = clock();
			// bubble_sort(array, lenght, 0);

			return clock() - start;
		}

		default: return 0;
	}
}

double measure(const Algorithm algorithm, const size_t lenght)
{
	int array[lenght];
	populate(array, lenght);

	clock_t elapsed = 0;

	for (size_t i = 0; i < Iterations; i++)
	{
		elapsed += timing(algorithm, array, lenght);
	}

	return ((double)elapsed / Iterations) / CLOCKS_PER_SEC;
}

Benchmark benchmark(const Algorithm algorithm)
{
	/* Initiate the predictive random generator to the same value
	   each time to create identical setting for every algorithm */
	srand(1234);

	Benchmark result;

	for (int i = 0; i < Variants; i++)
	{
		const size_t lenght = Initial * (2 * i);

		result.time[i].size = lenght;
		result.time[i].average = measure(algorithm, lenght);

		// TODO Add rest of data
	}

	return result;
}