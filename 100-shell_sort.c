#include "sort.h"

/**
 * shell_sort-Write a function that sort an array of integer
 * @array:list of array
 * @size: number of list
 */

void shell_sort(int *array, size_t size)
{
	size_t n = 0, i, j;
	int temp;

	while ((n = n * 3 + 1) < size)
		;

	n = (n - 1) / 3;

	for (; n > 0; n = (n - 1) / 3)
	{
		for (i = n; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= n && temp <= array[j - n]; j -= n)
				array[j] = array[j - n];
			array[j] = temp;
		}
		print_array(array, size);
	}
}
