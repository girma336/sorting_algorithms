#include "sort.h"

/**
 * quick_sort-write a function that print sort order
 * @array:list of array
 * @size:list size
 */

void quick_sort(int *array, size_t size)
{
	quick_recursion(array, 0, (int)size - 1, size);
}

/**
 * quick_recursion-Write a function recursion the number
 * @array:array of number
 * @start:index of the number
 * @end:index of end of list
 * @size:length of list
 */

void quick_recursion(int *array, int start, int end, size_t size)
{
	int pivot_index;

	if (start < end)
	{
		pivot_index = sort_pivot(array, start, end, size);
		quick_recursion(array, start, pivot_index - 1, size);
		quick_recursion(array, pivot_index + 1, end, size);
	}
}

/**
 * sort_pivot-sort the list by finding the pivot number
 * @array:array of list
 * @start:list start from 0
 * @end:list ends with size- 1
 * @size:end of list
 * Return:index of list
 */

int sort_pivot(int *array, int start, int end, size_t size)
{
	int i, j, temp;

	i = start - 1;
	for (j = start; j < end; j++)
	{
		if (array[j] < array[end])
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	if (array[end] < array[i + 1])
	{
		temp = array[i + 1];
		array[i + 1] = array[end];
		array[end] = temp;
		print_array(array, size);
	}
	return (i + 1);
}
