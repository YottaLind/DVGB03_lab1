
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

double measureSort(Sort algorithm, const size_t lenght, const Mode mode)
{
	int array[lenght];

	clock_t elapsed = 0;

	for (size_t i = 0; i < Iterations; i++)
	{
		switch (mode)
		{
			case Best:
			{
				break;
			}

			case Average: average(array, lenght); break;

			case Worst:
			{
				break;
			}
		}

		const clock_t start = clock();
		algorithm(array, lenght);
		elapsed += (clock() - start);
	}

	return ((double)elapsed / Iterations) / CLOCKS_PER_SEC;
}

static Search selectSearch(const Algorithm algorithm)
{
	switch (algorithm)
	{
		case LinearSearch: return linear_search;
		case BinarySearch: return binary_search;
		default: return NULL;
	}
}

static Sort selectSort(const Algorithm algorithm)
{
	switch (algorithm)
	{
		case BubbleSort: return bubble_sort;
		case InsertionSort: return insertion_sort;
		case QuickSort: return quick_sort;
		default: return NULL;
	}
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
		if (algorithm == LinearSearch || algorithm == BinarySearch)
		{
			// result.measurement[i].average = measureSort(algorithm, lenght, Average);
			// result.time[i].best = measure(algorithm, lenght);
			// result.time[i].worst = measure(algorithm, lenght);
		}
		else
		{
			result.measurement[i].average = measureSort(selectSort(algorithm), lenght, Average);
			// result.time[i].best = measure(algorithm, lenght);
			// result.time[i].worst = measure(algorithm, lenght);
		}
		result.measurement[i].size = lenght;

		lenght *= 2;
	}

	return result;
}