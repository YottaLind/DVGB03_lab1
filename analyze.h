#ifndef ANALYZE_H
#define ANALYZE_H

#include <stdint.h>

typedef enum Algorithmc
{
	BubbleSort,
	InsertionSort,
	QuickSort,
	LinearSearch,
	BinarySearch

} Algorithm;

typedef struct Measurement
{
	const unsigned int size;
	const double time;

} Measurement;

Measurement benchmark(const Algorithm algorithm, const unsigned int size);

#endif
