#ifndef MEASURE_H
#define MEASURE_H

#include "analyze.h"

#include <stdlib.h>

typedef void (*Sort)(int* array, int lenght);
typedef bool (*Search)(const int* array, int lenght, int value);
typedef void (*Initialize)(int* array, size_t lenght);

Measurement measureSort(const size_t lenght, Sort algorithm, Initialize best, Initialize average, Initialize worst);
Measurement measureSearch(const size_t lenght, Search algorithm, Initialize best, Initialize average, Initialize worst, int bestValue, int averageValue, int worstValue);

void randomly(int array[], const size_t lenght);
void forward(int array[], const size_t lenght);
void backward(int array[], const size_t lenght);

#endif
