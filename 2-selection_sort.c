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
	size_t i, j, flag = 0;
	int min_idx;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i += 1)
	{
		if (sorted_array(array, size) == 1)
			break;

		min_idx = i;
		for (j = i + 1; j < size; j += 1)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
				flag = 1;
			}
		}
		swap_arr(&array[i], &array[min_idx]);

		if (flag == 1)
			print_array(array, size);
		flag = 0;
	}
}

/**
 * swap_arr - swaps the 2 elements of an array
 * @a: item a
 * @b: item b
 *
 * Return: None
 */
void swap_arr(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sorted_array - checks if the array is sorted
 * @array: the array
 * @size: the size of the array
 *
 * Return: Returns 1 if array is sorted, 0 if array is unsorted
 */
int sorted_array(int *array, size_t size)
{
	int i;

	for (i = 0; i < (int) size - 1; i += 1)
	{
		if (array[i] > array[i + 1])
			return (0);
	}

	return (1);
}
