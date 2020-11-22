#include "algorithm.h"

#include <stdbool.h>

void bubble_sort(int* array, int lenght)
{
	for (int i = 0; i < lenght; i++)
	{
		bool switched = 0;
		for (int j = 0; j < lenght - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				switched = true;
				const int temporary = array[j];

				array[j] = array[j + 1];
				array[j + 1] = temporary;
			}
		}
		if (!switched) { return; }
	}
}

void insertion_sort(int* array, int lenght)
{
	for (int i = 1; i < lenght; i++)
	{
		const int key = array[i];
		int j = i - 1;

		while (j >= 0 && array[i] > key)
		{
			array[j + 1] = array[j];
			j--;
		}

		array[j + 1] = key;
	}
}

static void swap(int* const first, int* const second)
{
	const int temporary = *first;

	*first = *second;
	*second = temporary;
}

static int partition(int array[], int low, int high)
{
	int pivot = array[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;

			const int temporary = array[i];
			array[i] = array[j];
			array[j] = temporary;
		}
	}

	swap(&array[i + 1], &array[high]);

	return (i + 1);
}

static void quicksort_backend(int array[], const int start, const int end)
{
	if (start < end)
	{
		const int index = partition(array, start, end);

		quicksort_backend(array, start, index - 1);
		quicksort_backend(array, index + 1, end);
	}
}

void quick_sort(int* array, int lenght)
{
	quicksort_backend(array, 0, lenght - 1);
}

bool linear_search(const int* array, int lenght, int value)
{
	for (int i = 0; i < lenght; i++)
	{
		if (array[i] == value) { return true; }
	}
	return false;
}

bool binary_search(const int* array, int lenght, int value)
{
	int high = lenght - 1;
	int low = 0;

	while (low <= high)
	{
		const int middle = (low + high) / 2;

		if (array[middle] < value) { low = middle + 1; }
		else if (array[middle] > value)
		{
			high = middle - 1;
		}
		else
		{
			return true;
		}
	}
	return false;
}
