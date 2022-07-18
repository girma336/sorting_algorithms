#include "sort.h"

/**
 * merge_sort-Write a function tha print order list
 * @array:un order list
 * @size:size of unorder list
 */


void merge_sort(int *array, size_t size)
{
	int *new_arr;

	new_arr = malloc(sizeof(int) * size);

	merge_recursion(array, new_arr, 0, size);
	free(new_arr);
}

/**
 * merge_recursion-recursion of list
 * @array:list
 * @new_arr:new list
 * @start:list to start
 * @end:end of list
 */

void merge_recursion(int *array, int *new_arr, size_t start, size_t end)
{
	size_t mid;

	if ((end - start) > 1)
	{
		mid = (end - start) / 2 + start;
		merge_recursion(array, new_arr, start, mid);
		merge_recursion(array, new_arr, mid, end);
		merge_re_sort(array, new_arr, start, mid, end);
	}
}

/**
 * merge_re_sort-sort list by using divid and qu
 * @array:list of orginal array
 * @new_arr:new_orderd array
 * @start:list is start from 0
 * @end:list end in size
 * @mid:mid of list
 */

void merge_re_sort(int *array, int *new_arr, size_t start,
		size_t mid, size_t end)
{
	size_t i, j, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, end - mid);
	for (i = start, j = mid; i < mid && j < end; k++)
	{
		if (array[i] < array[j])
			new_arr[k] = array[i++];
		else
			new_arr[k] = array[j++];
	}
	while (i < mid)
		new_arr[k++] = array[i++];
	while (j < end)
		new_arr[k++] = array[j++];
	for (k = start, i = 0; k < end; k++)
	{
		array[k] = new_arr[i++];
	}

	printf("[Done]: ");
	print_array(array + start, end - start);
}
