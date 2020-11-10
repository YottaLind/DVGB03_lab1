#include "algorithm.h"

//
// Private
//

//
// Public
//
void bubble_sort(int *a, int n)
{
	// TODO: bubble sort
	int temp, i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void insertion_sort(int *a, int n)
{
	// TODO: insertion sort
}

void quick_sort(int *a, int n)
{
	// TODO: quick sort
}

bool linear_search(const int *a, int n, int v)
{
	quick_sort(a, n);
	int i = 0;
	while(a[i] <= v){
		if(a[i] == v){
			return true;
		}
		i++;
	}
	return false; // TODO: linear search
}

bool binary_search(const int *a, int n, int v)
{
	quick_sort(a, n);

	int low = 0, high = n-1, mid;
	while(low <= high){
		mid = (low+high)/2;
		if(a[mid] < v){
			low = mid + 1;
		}else if(a[mid > v]){
			high = mid-1;
		}else
		{
			return true;
		}
		
	}
	return false; // TODO: binary search
}
