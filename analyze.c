
#include "analyze.h"

#include "algorithm.h"
#include "measure.h"

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

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
				result.measurement[i] = measureSort(lenght, bubble_sort, forward, randomly, randomly);
				result.bigO.best_bigO = TN_t;
				result.bigO.worst_bigO = TN2_t;
				result.bigO.average_bigO = TN2_t;
				break;
			}

			case InsertionSort:
			{
				result.measurement[i] = measureSort(lenght, insertion_sort, forward, randomly, backward);
				break;
			}

			case QuickSort:
			{
				result.measurement[i] = measureSort(lenght, quick_sort, randomly, randomly, forward);
				break;
			}

			case LinearSearch:
			{
				/* Seed random number generator */
				srand(clock());

				result.measurement[i] = measureSearch(lenght, linear_search, forward, randomly, randomly, 0, rand(), -1);
				break;
			}

			case BinarySearch:
			{
				/* Seed random number generator */
				srand(clock());

				result.measurement[i] = measureSearch(lenght, binary_search, forward, forward, forward, (255 / 2), rand(), rand());
				break;
			}
		}

		lenght *= 2;
	}

	return result;
}