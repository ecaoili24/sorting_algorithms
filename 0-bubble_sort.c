#include "sort.h"

/**
 * bubble_sort - bubble sort
 * @array: array of integers
 * @size: size of array
 *
 * Return: None
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, p1, p2;
	size_t size2 = size;

	if (array == NULL || size == 0 || size < 2)
		return;

	for (i = 0; i <= size - 1; i += 1)
	{
		for (j = 0; j < size2 - i - 1; j += 1)
		{
			p1 = array[j];
			p2 = array[j + 1];

			if (p1 > p2)
			{
				int temp = p1;

				p1 = p2;
				p2 = temp;

				array[j] = p1;
				array[j + 1] = p2;
				print_array(array, size);
			}
		}
	}
}
