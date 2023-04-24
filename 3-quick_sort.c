#include "sort.h"

void swap(int *x, int *y, int *array, size_t size);
void quick_sort_recursion(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);

/**
 * quick_sort - sorts array using quicksort
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursion(array, 0, size - 1, size);
}

/**
 * swap - swaps items in array
 * @x: first item to swap
 * @y: item 2
 * @array: array to be printed after swap
 * @size: size of array
 */
void swap(int *x, int *y, int *array, size_t size)
{
	int tmp = *x;

	*x = *y;
	*y = tmp;
	print_array((const int *)array, size);
}

/**
 * quick_sort_recursion - quicksorts recursively
 * @array: array to sort
 * @low: low bound
 * @high: high bound
 * @size: size of array
 */
void quick_sort_recursion(int *array, int low, int high, size_t size)
{
	if (low < high) /* more than 2 items in array */
	{
		int pivot_index;

		pivot_index = partition(array, low, high, size);
		quick_sort_recursion(array, low, pivot_index - 1, size);
		quick_sort_recursion(array, pivot_index + 1, high, size);
	}
}

/**
 * partition - partition array
 * @array: array to partition
 * @low: low bound
 * @high: high bound
 * @size: size of array
 *
 * Return: partition index
 */
int partition(int *array, int low, int high, size_t size)
{
	int pvalue = array[high]; /* last element (lomuto partitioning) */
	int i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pvalue)
		{
			if (i != j)
				swap(&array[i], &array[j], array, size);
			++i;
		}
	}
	if (i != high)
		swap(&array[i], &array[high], array, size); /* swap pivot */
	return (i);
}
