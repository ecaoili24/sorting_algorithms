#include "sort.h"

/**
 * counting_sort - a function that sorts an array of integers
 * in ascending order using the Counting sort algorithm
 * @array: array of integers
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	int i, j, k, m, n, *count_arr, *output;
	int max = array[0];

	if (array == NULL || size < 2)
		return;

	for (i = 1; i < (int) size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count_arr = calloc(sizeof(int), max + 1);

	for (j = 0; j < (int) size; j++)
		count_arr[array[j]] += 1;

	for (k = 1; k <= max; k++)
	{
		count_arr[k] += count_arr[k - 1];
	}

	output = malloc(sizeof(int) * size);

	for (m = size - 1; m >= 0; m--)
	{
		output[count_arr[array[m]] - 1] = array[m];
	}

	for (n = 0; n < (int) size; n++)
	{
		array[n] = output[n];
	}
	print_array(count_arr, max + 1);
	free(output);
	free(count_arr);
}
