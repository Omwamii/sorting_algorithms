#include "sort.h"

void swap(int *x, int *y);
/**
 * shell_sort - sorts array using shell sort algo
 * @array: array to be sorted
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	int i, swp = 0;
	size_t j, gap = 1;

	while (gap < size)
	{
		gap = (gap * 3) + 1;
	}

	while (gap >= 1)
	{
		for (j = gap; j < size; j++)
		{
			for (i = j - gap; i >= 0; i -= gap)
			{
				if (array[i + gap] > array[i]) /* no need to swap */
					break;
				swap(&array[i + gap], &array[i]);
				swp = 1;
			}
		}
		gap /= 3;
		if (swp)
			print_array(array, size);
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
