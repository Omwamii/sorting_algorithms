#include "sort.h"

void swap(int *x, int *y);
void quick_sort_recursion(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);

/**
 * quick_sort_hoare - sorts array using hoare quicksort algo
 * @array: array to be sorted
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursion(array, 0, size - 1, size);
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
		quick_sort_recursion(array, low, pivot_index, size);
		quick_sort_recursion(array, pivot_index + 1, high, size);
	}
}

/**
 * partition - partitions array , sorting
 * @array: array to be partitioned
 * @low: low bound
 * @high: high bound
 * @size: size of original array
 *
 * Return: partition index
 */
int partition(int *array, int low, int high, size_t size)
{
	int pval = array[high], i = low - 1, j = high + 1;

	while (1)
	{
		if (i > j)
			break;
		do {
			i++;
		} while (array[i] < pval);
		do {
			j--;
		} while (array[j] > pval);

		if (i < j)
		{
			swap(&array[i], &array[j]);
			print_array((const int *)array, size);
		}
	}
	return (j);
}

/**
 * swap - swaps items in array
 * @x: first item to swap
 * @y: item 2
 */
void swap(int *x, int *y)
{
	int tmp = *x;

	*x = *y;
	*y = tmp;
	/*print_array((const int *)array, size);*/
}
