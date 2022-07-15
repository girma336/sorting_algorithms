#include "sort.h"

/**
 * selection_sort-Write a function that sort an array of integer
 * @array:list of array
 * @size:lenght of array size
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, num;
	int temp;

	for (i = 0; i < size; i++)
	{
		num = i;
		for (j = i + 1; j < size; j++)
		{

			if (array[j] < array[num])
			{
				num = j;
			}
		}
		temp = array[i];
		array[i] = array[num];
		array[num] = temp;
		if (i != num)
			print_array(array, size);
	}
}
