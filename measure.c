#include "measure.h"

#include "algorithm.h"
#include "analyze.h"

#include <stdlib.h>
#include <time.h>

static clock_t timingSort(Sort algorithm, int array[], const size_t lenght)
{
	const clock_t start = clock();

	algorithm(array, lenght);

	return clock() - start;
}

static clock_t timingSearch(Search algorithm, int array[], const size_t lenght, const int value)
{
	const clock_t start = clock();

	algorithm(array, lenght, value);

	return clock() - start;
}

static double computeSort(const size_t lenght, Sort algorithm, Initialize initialize)
{
	int array[lenght];
	clock_t elapsed = 0;

	for (size_t i = 0; i < IterationsSort; i++)
	{
		initialize(array, lenght);

		elapsed += timingSort(algorithm, array, lenght);
	}
	return ((double)elapsed / IterationsSort) / CLOCKS_PER_SEC;
}

static double computeSearch(const size_t lenght, Search algorithm, Initialize initialize, const int value)
{
	int array[lenght];
	clock_t elapsed = 0;

	for (size_t i = 0; i < IterationsSearch; i++)
	{
		initialize(array, lenght);

		elapsed += timingSearch(algorithm, array, lenght, value);
	}
	return ((double)elapsed / IterationsSearch) / CLOCKS_PER_SEC;
}

Measurement measureSort(const size_t lenght, Sort algorithm, Initialize best, Initialize average, Initialize worst)
{
	/* Seed random number generator */
	srand(clock());

	Measurement result;
	result.size = lenght;

	result.best = computeSort(lenght, algorithm, best);
	result.average = computeSort(lenght, algorithm, average);
	result.worst = computeSort(lenght, algorithm, worst);

	return result;
}

Measurement measureSearch(const size_t lenght, Search algorithm, Initialize best, Initialize average, Initialize worst, int bestValue, int averageValue, int worstValue)
{
	/* Seed random number generator */
	srand(clock());

	Measurement result;
	result.size = lenght;

	result.best = computeSearch(lenght, algorithm, best, bestValue);
	result.average = computeSearch(lenght, algorithm, average, averageValue);
	result.worst = computeSearch(lenght, algorithm, worst, worstValue);

	return result;
}

void randomly(int array[], const size_t lenght)
{
	for (int index = 0; index < lenght; index++)
	{
		array[index] = rand();
	}
}

void forward(int array[], const size_t lenght)
{
	for (int index = 0; index < lenght; index++)
	{
		array[index] = index;
	}
}

void backward(int array[], const size_t lenght)
{
	for (int index = 0; index < lenght; index++)
	{
		array[index] = lenght - index;
	}
}