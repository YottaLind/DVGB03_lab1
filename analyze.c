
#include "analyze.h"

#include "algorithm.h"
#include "measure.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

Benchmark benchmark(const Algorithm algorithm)
{
	Benchmark result;
	result.algorithm = algorithm;

	size_t lenght = Initial;

	for (int i = 0; i < Variants; i++)
	{
		switch (algorithm)
		{
			case BubbleSort:
			{
				result.measurement[i] = measureSort(lenght, bubble_sort, forward, random, random);
				break;
			}

			case InsertionSort:
			{
				result.measurement[i] = measureSort(lenght, insertion_sort, forward, random, backward);
				break;
			}

			case QuickSort:
			{
				result.measurement[i] = measureSort(lenght, quick_sort, random, random, forward);
				break;
			}

			case LinearSearch:
			{
				break;
			}
			case BinarySearch:
			{
				break;
			}
		}

		lenght *= 2;
	}

	return result;
}