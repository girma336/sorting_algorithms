#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*all given heder file*/

void bubble_sort(int *array, size_t size);
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void insertion_sort_list(listint_t **list);
int len_size(listint_t *list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_recursion(int *array, int start, int end, size_t size);
int sort_pivot(int *array, int start, int end, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void support_list(listint_t **list, listint_t **nw);
void counting_sort(int *array, size_t size);
void merge_re_sort(int *array, int *new_arr, size_t start,
		   size_t mid, size_t end);
void merge_sort(int *array, size_t size);
void merge_recursion(int *array, int *new_arr, size_t start, size_t end);
void heapify(int *array, size_t subt, size_t root, size_t size);
void heap_sort(int *array, size_t size);
void sort_lsd(int *array, size_t size, size_t lsd);
void radix_sort(int *array, size_t size);
#endif
