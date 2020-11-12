#ifndef ANALYZE_H
#define ANALYZE_H

#include <stdint.h>


#define Iteartions 6

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

typedef struct Result
{
	Measurement best[Iteartions];
	Measurement average[Iteartions];
	Measurement worst[Iteartions];

} Result;


void benchmark(const Algorithm algorithm, const unsigned int size);

#endif
