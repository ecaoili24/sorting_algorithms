/**
 * swap - swaps the 2 elements of an array
 * @array: array of integers
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
