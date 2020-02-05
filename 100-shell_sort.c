#include "sort.h"

/**
 * shell_sort - selection sort
 * @array: array of integers
 * @size: size of array
 *
 * Return: None
 */
void shell_sort(int *array, size_t size)
{
	int h = 1;
	int i, n;

	if (array == NULL || size < 2)
		return;

	while (h < (int) size / 3)
	{
		h = h * 3 + 1;
	}

	while (h > 0)
	{
		for (i = h; i < (int) size; i += 1)
		{
			for (n = i; n > 0 && array[n] < array[n - h]; n -= h)
			{
				int number = array[n];

				array[n] = array[n - h];
				array[n - h] = number;
			}
		}
		h = (h - 1) / 3;
		i++;
		print_array(array, size);
	}
}
