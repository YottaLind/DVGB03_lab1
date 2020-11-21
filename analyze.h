#ifndef ANALYZE_H
#define ANALYZE_H

#include <stdbool.h>
#include <stdlib.h>

#define Variants   6
#define Initial	   256
#define Iterations 100

typedef enum Algorithm
{
	BubbleSort,
	InsertionSort,
	QuickSort,
	LinearSearch,
	BinarySearch

} Algorithm;

typedef struct Measurement
{
	double best;
	double average;
	double worst;

	size_t size;

} Measurement;

typedef struct Benchmark
{
	Measurement measurement[Variants];
	Algorithm algorithm;

} Benchmark;

Benchmark benchmark(const Algorithm algorithm);

#endif
