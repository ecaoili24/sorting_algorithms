#include "sort.h"

/**
 * selection_sort - selection sort
 * @array: array of integers
 * @size: size of array
 *
 * Return: None
 */

void quick_sort(int *array, size_t size)
{
	qwiksort(array, 0, (int) size - 1, size);
}


void qwiksort(int *array, int lo, int hi, size_t size)
{
	if (lo < hi)
	{
		/*pivot*/
		int p = partition(array, lo, hi, size);
		/*left partition*/
		qwiksort(array, lo, p - 1, size);

		/*right parititon*/
		qwiksort(array, p + 1, hi, size);
	}
}


int partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int i = (lo - 1), j;

	for (j = lo; j <= hi - 1; j += 1)
	{
		if (array[j] < (int) pivot)
		{
			/* increment i then swap*/
			i += 1;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[hi]);
	print_array(array, size);
	return (i + 1);
}
/**
 * swap - swaps the 2 elements of an array
 * @idx1: index1
 * @idx2: index2
 *
 * Return: None
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
