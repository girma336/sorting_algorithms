#include "sort.h"

/**
 * counting_sort-Write a function that sorts an array of int
 * @array:unsorted list
 * @size:size of unsorted list
 */

void counting_sort(int *array, size_t size)
{
	int *counting, l, k, *single, max, num;
	size_t i, j, m, n;

	if (size < 2)
		return;
	max = array[0];
	for (i = 1; i < size; i++)
		if (max < array[i])
			max = array[i];
	counting = malloc(sizeof(size_t) * (max + 1));
	single = malloc(sizeof(int) * size);

	for (k = 0; k <= max; k++)
		counting[k] = 0;
	for (j = 0; j < size; j++)
	{
		num = array[j];
		counting[num] += 1;
	}
	for (l = 1; l <= max; l++)
	{
		counting[l] += counting[l - 1];
	}
	print_array(counting, max + 1);
	for (m = 0; m < size; m++)
	{
		single[counting[array[m]] - 1] = array[m];
		counting[array[m]]--;
	}
	for (n = 0; n < size; n++)
		array[n] = single[n];
	free(counting);
	free(single);
}
