
#include "analyze.h"

#include "algorithm.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef void (*Sort)(int* array, int lenght);
typedef bool (*Search)(const int* array, int lenght, int value);

void average(int array[], const size_t lenght)
{
	for (int index = 0; index < lenght; index++)
	{
		array[index] = rand();
	}
}

static clock_t timingSort(Sort algorithm, int array[], const size_t lenght)
{
	const clock_t start = clock();

	algorithm(array, lenght);

	return clock() - start;
}

static Measurement measureQuicksort(const size_t lenght)
{
	Measurement result;
	result.size = lenght;

	/* Average */
	{
		int array[lenght];
		clock_t elapsed = 0;

		for (size_t i = 0; i < Iterations; i++)
		{
			/* Initiate array to random values */
			for (int index = 0; index < lenght; index++)
			{
				array[index] = rand();
			}

			elapsed += timingSort(quick_sort, array, lenght);
		}
		result.average = ((double)elapsed / Iterations) / CLOCKS_PER_SEC;
	}

	/* Best */
	{}

	/* Worst */
	{
	}

	return result;
}

Benchmark benchmark(const Algorithm algorithm)
{
	/* Seed random number generator */
	srand(clock());

	Benchmark result;
	result.algorithm = algorithm;

	size_t lenght = Initial;

	for (int i = 0; i < Variants; i++)
	{
		switch (algorithm)
		{
			case BubbleSort:
			case InsertionSort:
			case QuickSort:
			{
				result.measurement[i] = measureQuicksort(lenght);
				break;
			}

			case LinearSearch:
			case BinarySearch: break;
		}

		lenght *= 2;
	}

	return result;
}