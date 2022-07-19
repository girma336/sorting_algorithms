#include "sort.h"


/**
 * radix_sort-Write a function that sorts an array of integer
 * @array: That hold the list
 * @size: Size of the list
 */


void radix_sort(int *array, size_t size)
{
	int max;
	size_t i, lsd;

	if (!array || size < 2)
		return;

	max = array[0];
	for (i = 0; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}

	for (lsd = 1; max / lsd > 0; lsd *= 10)
	{
		sort_lsd(array, size, lsd);
		print_array(array, size);
	}
}

/**
 * sort_lsd-implement the LSD radix sort algorithm
 * @array: list of array
 * @size: of list
 * @lsd: list
 */

void sort_lsd(int *array, size_t size, size_t lsd)
{
	int count_arr[10] = {0}, *arr, l, m;
	size_t k, n;

	arr = malloc(sizeof(int) * size);

	for (k = 0; k < size; k++)
		count_arr[(array[k] / lsd) % 10]++;
	for (l = 1; l < 10; l++)
		count_arr[l] += count_arr[l - 1];

	for (m = size - 1; m >= 0; m--)
	{
		arr[count_arr[(array[m] / lsd) % 10] - 1] = array[m];
		count_arr[(array[m] / lsd) % 10]--;
	}

	for (n = 0; n < size; n++)
		array[n] = arr[n];

	free(arr);
}
