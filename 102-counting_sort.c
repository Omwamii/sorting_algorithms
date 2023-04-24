#include "sort.h"

/**
 * counting_sort - sorts array using counting sort
 * @array: array to be sorted
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int *tmp1, *tmp2, k, i, len = size;

	if (array == NULL || size <= 0)
		return;

	k = array[0];
	for (i = 0; i < len; i++)
	{
		if (k < array[i])
			k  = array[i];
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
	for (i = 0; i < (k + 1); i++) /* set all values to 0 */
		tmp1[i] = 0;
	for (i = 0; i < len; i++) /* increment tmp1 value count */
		++(tmp1[array[i]]);
	for (i = 1; i <= k; i++) /* increment values in tmp1 to match indices */
		tmp1[i] = tmp1[i] + tmp1[i - 1];
	print_array(tmp1, k + 1);
	for (i = len - 1; i >= 0; i--)
		tmp2[--(tmp1[array[i]])] = array[i];
	for (i = 0; i < len; i++)
		array[i] = tmp2[i];
	free(tmp1);
	free(tmp2);
}
