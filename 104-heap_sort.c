#include "sort.h"

void swap(int *x, int *y);
void heapify(int *array, int n, int i, size_t size);
/**
 * heap_sort - sorts array using heap sort
 * @array: array to be sorted
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	int i, n;

	if (array == NULL || size < 2)
		return;
	n = size - 1;
	for (i = (n / 2); i >= 0; i--) /* heapify each sub-tree to top */
		heapify(array, n, i, size);
	for (i = n; i >= 0; i--) /* delete nodes from root */
	{
		if (i == 0) /* no need to swap last element */
			break;
		swap(&array[0], &array[i]);
		print_array((const int *)array, size);
		n -= 1;
		heapify(array, n, 0, size);
	}
}

/**
 * heapify - builds max heap of array
 * @array: array to be sorted
 * @n: size of array
 * @i: index for largest item in heap / sub-tree
 * @size: size of array
 */
void heapify(int *array, int n, int i, size_t size)
{
	int largest = i;
	int left = (2 * i) + 1;
	int right = left + 1;

	while (left <= n && array[left] > array[largest])
		largest = left;
	while (right <= n && array[right] > array[largest])
		largest = right;
	if (largest != i)
	{
		swap(&array[largest], &array[i]);
		print_array((const int *)array, size);
		heapify(array, n, largest, size);
	}
}

/**
 * swap - swap elements in array
 * @x: first el
 * @y: second el
 */
void swap(int *x, int *y)
{
	int tmp = *x;

	*x = *y;
	*y = tmp;
}
