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

	while (h <= (int) size / 3)
	{
		h = h * 3 + 1;
	}

	while (h >= 1)
	{
		for (i = h; i < (int) size; i += 1)
		{
			int number = array[i];

			for (n = i; n >= h  && number < array[n - h]; n -= h)
			{
				array[n] = array[n - h];
			}
			array[n] = number;
		}
		h = (h - 1) / 3;
		print_array(array, size);
	}
}
