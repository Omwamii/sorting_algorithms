#include "sort.h"

void merge_recursion(int *array, int low, int high, int *tmp);
void merge(int *array, int low, int mid, int high, int *tmp);
/**
 * merge_sort - sorts array with merge sort
 * @array: array to sort
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (array == NULL || size <= 0)
		return;
	tmp = malloc(size * sizeof(int));
	if (tmp == NULL)
		return;
	merge_recursion(array, 0, size - 1, tmp);
	free(tmp);
}

/**
 * merge_recursion - merge array into sub-arrays recursively until single el
 * @array: array being sorted
 * @low: low bound
 * @high: high bound
 * @tmp: temp array used in merges
 */
void merge_recursion(int *array, int low, int high, int *tmp)
{
	if (low < high)
	{
		int mid = (low + high + 1) / 2;

		merge_recursion(array, low, mid - 1, tmp); /* break to left sub-arrays */
		merge_recursion(array, mid, high, tmp); /* right sub-arrays */
		merge(array, low, mid - 1, high, tmp);
	}
}

/**
 * merge - merges two sub-arrays into one array
 * @array: array being sorted
 * @low: low bound of sub-array 1
 * @mid: high bound of sub-array 1
 * @high: high bound of sub-array 2
 * @tmp: temporary array used in merges
 */
void merge(int *array, int low, int mid, int high, int *tmp)
{
	int i = low, j = mid + 1, k = low, l;

	printf("Merging...\n");
	printf("[left]: ");
	for (l = low; l <= mid; l++)
	{
		printf("%d", array[l]);
		if (l != mid)
			printf(", ");
	}
	printf("\n");
	printf("[right]: ");
	for (l = mid + 1; l <= high; l++)
	{
		printf("%d", array[l]);
		if (l != high)
			printf(", ");
	}
	printf("\n");
	while (i <= mid && j <= high)
	{
		if (array[i] <= array[j])
		{
			tmp[k] = array[i];
			i++;
		}
		else
		{
			tmp[k] = array[j];
			j++;
		}
		k++;
	}
	if (i > mid)
	{
		while (j <= high)
			tmp[k++] = array[j++];
	}
	else
	{
		while (i <= mid)
			tmp[k++] = array[i++];
	}
	for (i = low; i <= high; i++)
		array[i] = tmp[i];
	printf("[Done]: ");
	for (l = low; l <= high; l++)
	{
		printf("%d", array[l]);
		if (l != high)
			printf(", ");
	}
	printf("\n");
}
