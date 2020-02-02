#include "sort.h"

/**
 * selection_sort - selection sort
 * @array: array of integers
 * @size: size of array
 *
 * Return: None
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min_idx;

	for (i = 0; i < size -1; i += 1)
	{
		min_idx = i;
		for (j = i + 1; j < size; j += 1)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		swap(array, i, min_idx);
		print_array(array, size);
	}
}

/**
 * swap - swaps the 2 elements of an array
 * @array: array of integers
 * @idx1: index 1
 * @idx2: index 2
 *
 * Return: None
 */
void swap(int *array, int idx1, int idx2)
{
	int temp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = temp;
}
