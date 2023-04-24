#include "sort.h"

void swap(int *x, int *y);
/**
 * selection_sort - sorts array with selection sort
 * @array: array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < (size - 1); i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min] > array[j])
				min = j;
		}
		if (min != i)
		{
			swap(&array[min], &array[i]);
			print_array((const int *)array, size);
		}

	}
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
}
