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
	count_arr = malloc(sizeof(int) * (max + 1));
	if (count_arr == NULL)
		return;

	for (i = 0; i <= max; i++)
		count_arr[i] = 0;

	for (j = 0; j < (int) size; j++)
		count_arr[array[j]] += 1;

	for (k = 1; k <= max; k++)
		count_arr[k] += count_arr[k - 1];

	print_array(count_arr, max + 1);
	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(count_arr);
		return;
	}
	for (m = 0; m < (int) size; m++)
	{
		count_arr[array[m]]--;
		output[count_arr[array[m]]] = array[m];
	}
	for (n = 0; n < (int) size; n++)
		array[n] = output[n];
	free(output);
	free(count_arr);
}
