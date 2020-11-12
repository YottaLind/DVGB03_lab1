#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <stdbool.h>

/* Sorting algorithms */

void bubble_sort(int *array, int lenght);

void insertion_sort(int *array, int lenght);

void quick_sort(int *array, int lenght);



/* Search algorithms */

bool linear_search(const int *array, int lenght, int value);

bool binary_search(const int *array, int lenght, int value);

#endif
