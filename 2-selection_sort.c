#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                   using the Selection sort algorithm.
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int temp, swap;

	if (array == NULL || size < 2)
	return;

	for (i = 0; i < size - 1; i++)
	{
	min_idx = i;
	swap = 0;
	for (j = i + 1; j < size; j++)
	{
	if (array[j] < array[min_idx])
	{
		min_idx = j;
		swap = 1;
	}
	}

	if (swap != 0)
	{
	temp = array[i];
	array[i] = array[min_idx];
	array[min_idx] = temp;
	print_array(array, size);
	}
	}
}
