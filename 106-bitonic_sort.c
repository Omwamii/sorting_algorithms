#include "sort.h"

void cmpSwap(int *array, int i, int j, int direction);
void bSort(int *array, int low, int count, int direction, size_t size);
void bMerge(int *array, int low, int count, int direction);

/**
 * bitonic_sort - sorts arrray in ascending using bitonic sort
 * @array: array to be sorted
 * @size: size of array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL)
		return;
	 bSort(array, 0, size, 1, size); /* sort recursively in ascending order */
}

/**
 * bSort - creates bitonic sequences recursivley and calls merge
 * @array: array to sort
 * @low: low bound
 * @count: number of elements
 * @direction: direction of sort (ascending - 1, descending - 0)
 * @size: size of array
 */
void bSort(int *array, int low, int count, int direction, size_t size)
{
	int k;

	if (count > 1)
	{
		printf("Merging [%u/%lu] %s:\n", count, size, direction == 1 ?
				"(UP)" : "(DOWN)");
		print_array(&array[low], count);

		k = count / 2;
		bSort(array, low, k, 1, size); /* sort in ascending */
		bSort(array, low + k, k, 0, size); /* sort portion in descending */
		bMerge(array, low, count, direction);

		printf("Result [%u/%lu] %s:\n", count, size, direction == 1 ?
				"(UP)" : "(DOWN)");
		print_array(&array[low], count);
	}
}

/**
 * bMerge - merges bitonic sequences while sorting
 * @array: array to sort
 * @low: low bound
 * @count: number of elements
 * @direction: direction of sort (ascending - 1, descending - 0)
 */
void bMerge(int *array, int low, int count, int direction)
{
	if (count > 1)
	{
		int k = count / 2, i;

		for (i = low; i < low + k; i++)
			cmpSwap(array, i, i + k, direction);
		bMerge(array, low, k, direction);
		bMerge(array, low + k, k, direction);

	}
}

/**
 * cmpSwap - compares and swaps array elements
 * @array: array with elements
 * @i: index of el1
 * @j: index of el2
 * @direction: direction of comparison
 */
void cmpSwap(int *array, int i, int j, int direction)
{
	int tmp;

	if (direction == (array[i] > array[j]))
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}
