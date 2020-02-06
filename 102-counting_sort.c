#include "sort.h"

/**
 * counting_sort - a function that sorts an array of integers
 * in ascending order using the Counting sort algorithm
 * @array: array of integers
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t i, j, k, m, n, max;
	int *count_arr, *output;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > (int) max)
			max = array[i];
	}
	count_arr = calloc(sizeof(int), max + 1);
	if (count_arr == NULL)
		return;

	for (j = 0; j < size; j++)
		count_arr[array[j]] += 1;

	for (k = 1; k <= max; k++)
		count_arr[k] += count_arr[k - 1];

	print_array(count_arr, max + 1);
	output = malloc(sizeof(int) * size);

	for (m = 0; m < size; m++)
	{
		output[count_arr[array[m]] - 1] = array[m];
		count_arr[array[m]]--;
	}
	for (n = 0; n < size; n++)
		array[n] = output[n];
	free(output);
	free(count_arr);
}
