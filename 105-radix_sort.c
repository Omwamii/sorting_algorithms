#include "sort.h"

int getmax(int *array, size_t size);
void countsort(int *array, size_t size, int pos);
/**
 * radix_sort - sorts array with radix sort
 * @array: array to be sorted
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int max, pos;

	if (array == NULL || size < 2)
		return;
	max = getmax(array, size);
	for (pos = 1; max / pos > 0; pos *= 10)
	{
		countsort(array, size, pos);
	}
}

/**
 * getmax - get max number in array
 * @array: array to be searched
 * @size: size of array
 *
 * Return: max integer
 */
int getmax(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * countsort - uses countsort to sort array based on signif digit
 * @array: array to be sorted
 * @size: size of array
 * @pos: position (ones, tens)
 */
void countsort(int *array, size_t size, int pos)
{
	int *tmp1, *tmp2, k, i, tmp;

	k = (array[0] / pos) % 10;
	for (i = 0; i < (int)size; i++)
	{
		if ((array[i] / pos) % 10 > k) /* find largest significant digit */
			k = (array[i] / pos) % 10;
	}
	tmp1 = malloc((k + 1) * sizeof(int));
	if (tmp1 == NULL)
		return;
	tmp2 = malloc(size * sizeof(int));
	if (tmp2 == NULL)
	{
		free(tmp1);
		return;
	}
	for (i = 0; i < k + 1; i++) /* set all values to 0 */
		tmp1[i] = 0;
	for (i = 0; i < (int)size; i++)
		++tmp1[(array[i] / pos) % 10];
	for (i = 1; i < k + 1; i++)
		tmp1[i] = tmp1[i] + tmp1[i - 1];
	for (i = (size - 1); i >= 0; i--) /* set tmp2 by real values from count */
	{
		tmp = array[i];
		tmp2[--tmp1[(tmp / pos) % 10]] = tmp;
	}
	for (i = 0; i < (int)size; i++) /* copy values to main */
		array[i] = tmp2[i];
	print_array((const int *)array, size);
	free(tmp1);
	free(tmp2);
}
