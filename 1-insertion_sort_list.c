#include "sort.h"

/**
 * insertion_sort_list-write a function that sort a doubly linked
 * @list:double linked list
 */


void insertion_sort_list(listint_t **list)
{
	listint_t *temp_1 = NULL, *temp_2 = NULL;
	listint_t *curr, *temp = NULL, *temp_3 = NULL;

	if (!list || !(*list) || len_size(*list) < 2)
		return;

	curr = *list;

	while (curr)
	{
		if (curr->prev && curr->n < curr->prev->n)
		{
			temp_1 = curr->prev->prev;
			temp_2 = curr->prev;
			temp = curr;
			temp_3 = curr->next;

			temp_2->next = temp_3;
			if (temp_3)
				temp_3->prev = temp_2;
			temp->next = temp_2;
			temp->prev = temp_1;
			if (temp_1)
				temp_1->next = temp;
			else
				*list = temp;
			temp_2->prev = temp;
			curr = *list;
			print_list(*list);
			continue;
		}
		else
			curr = curr->next;
	}
}

/**
 * len_size - write a function that print length
 * @list:list of list
 * Return:len_size
 */
int len_size(listint_t *list)
{
	unsigned int i = 0;

	while (list)
	{
		i++;
		list = list->next;
	}

	return (i);
}
