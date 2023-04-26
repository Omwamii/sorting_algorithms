#include <stdio.h>
#include <stdlib.h>
#include "../sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {1, 2, 20, 21, 22, 31, 32, 34, 39, 41, 47, 62, 68, 79, 84, 87, 91, 92, 95, 98};
	size_t n = sizeof(array) / sizeof(array[0]);/* 20 */

	print_array(array, n);
	printf("\n");
	shell_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
