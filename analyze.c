
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
				result.bigO.average_bigO = TN2_t;
				result.bigO.worst_bigO = TN2_t;

				break;
			}

			case InsertionSort:
			{
				result.measurement[i] = measureSort(lenght, insertion_sort, forward, randomly, backward);

				result.bigO.best_bigO = TN_t;
				result.bigO.average_bigO = TN2_t;
				result.bigO.worst_bigO = TN2_t;

				break;
			}

			case QuickSort:
			{
				result.measurement[i] = measureSort(lenght, quick_sort, randomly, randomly, forward);

				result.bigO.best_bigO = TNlogN_t;
				result.bigO.average_bigO = TNlogN_t;
				result.bigO.worst_bigO = TN2_t;

				break;
			}

			case LinearSearch:
			{
				/* Seed random number generator */
				srand(clock());

				result.measurement[i] = measureSearch(lenght, linear_search, forward, randomly, randomly, 0, rand(), -1);

				result.bigO.best_bigO = One_t;
				result.bigO.average_bigO = TN2_t;
				result.bigO.worst_bigO = TN_t;

				break;
			}

			case BinarySearch:
			{
				/* Seed random number generator */
				srand(clock());

				result.measurement[i] = measureSearch(lenght, binary_search, forward, forward, forward, (lenght / 2), rand(), rand());

				result.bigO.best_bigO = One_t;
				result.bigO.average_bigO = TlogN_t;
				result.bigO.worst_bigO = TlogN_t;

				break;
			}
		}

		lenght *= 2;
	}

	return result;
}