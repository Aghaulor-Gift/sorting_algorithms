#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Partitions the array using the Lomuto scheme
 * @array: Pointer to the array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 * Return: Index of the pivot element
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
	if (array[j] < pivot)
	{
	i++;
	if (i != j)
	{
	swap(&array[i], &array[j]);
	print_array(array, size);
	}
	}
	}
	if (array[i + 1] != array[high])
	{
	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - Recursively sorts the array using Quick sort algorithm
 * @array: Pointer to the array to be sorted
 * @low: Starting index of the array
 * @high: Ending index of the array
 * @size: Number of elements in the array
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
	pi = lomuto_partition(array, low, high, size);
	quicksort(array, low, pi - 1, size);
	quicksort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *               using the Quick sort algorithm.
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	return;

	quicksort(array, 0, size - 1, size);
}
