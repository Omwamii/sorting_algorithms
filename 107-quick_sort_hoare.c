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
	int pval = array[high], i = low, j = high;

	while (1)
	{
		while (array[i] <= pval)
			i++;
		while (array[j] > pval)
			j--;
		if (i > j)
		{
			if (j == high) /* value is at max, sorted */
				return (j - 1);
			return (j);
		}
		swap(&array[i], &array[j]);
		print_array((const int *)array, size);
	}
}

/**
 * swap - swaps items in array
 * @x: first item to swap
 * @y: item 2
 * @array: array to be printed after swap
 * @size: size of array
 */
void swap(int *x, int *y)
{
	int tmp = *x;

	*x = *y;
	*y = tmp;
	/*print_array((const int *)array, size);*/
}
