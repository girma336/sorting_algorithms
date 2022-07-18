#include "sort.h"


/**
 * heap_sort-write a function that sort list by using heap
 * @array: List of unOrder list
 * @size: Size of array
 */

void heap_sort(int *array, size_t size)
{
	int i, temp;
	int par;

	par = (size / 2) - 1;

	for (i = par; i >= 0; i--)
		heapify(array, size, (size_t)i, size);
	for (i = size - 1; i >= 0; i--)
	{
		temp = array[i];
		array[i] = array[0];
		array[0] = temp;

		if (i != 0)
			print_array(array, size);
		heapify(array, (size_t)i, 0, size);
	}
}

/**
 * heapify- That bulids a heap from a list in O(n)
 * @array:list of array
 * @subt:size of sub tree
 * @root: index of root
 * @size:length of array
 */

void heapify(int *array, size_t subt, size_t root, size_t size)
{
	int temp;
	size_t max, left, right;

	max = root;
	left = (root * 2) + 1;
	right = (root * 2) + 2;

	if (left < subt && array[left] > array[max])
		max = left;
	if (right < subt && array[right] > array[max])
		max = right;
	if (max != root)
	{
		temp = array[root];
		array[root] = array[max];
		array[max] = temp;
		print_array(array, size);
		heapify(array, subt, max, size);
	}
}
