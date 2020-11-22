#ifndef ANALYZE_H
#define ANALYZE_H

#include <stdbool.h>
#include <stdlib.h>

#define Variants   6
#define Initial	   256
#define Iterations 4

typedef enum Algorithm
{
	BubbleSort,
	InsertionSort,
	QuickSort,
	LinearSearch,
	BinarySearch

} Algorithm;

typedef enum O_Notation{
	One_t = 1,
	TlogN_t = 1,
	TN_t = 2,
	TNlogN_t = 3,
	TN2_t = 4,
	TN3_t = 4
}O_Notation;

typedef struct Measurement
{
	double best;
	double average;
	double worst;

	size_t size;

} Measurement;

typedef struct BigO
{
	O_Notation best_bigO;
	O_Notation worst_bigO;
	O_Notation average_bigO;
}BigO;


typedef struct Benchmark
{
	Measurement measurement[Variants];
	Algorithm algorithm;
	BigO bigO;

} Benchmark;

Benchmark benchmark(const Algorithm algorithm);

#endif
