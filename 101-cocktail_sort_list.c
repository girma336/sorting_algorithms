#include "sort.h"

/**
 * len_size-Write a function that sorts a double linke
 * @list:list of linked list
 * Return:lenght of list
 */

int len_size(listint_t *list)
{
	int len = 0;

	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}
/**
 * cocktail_sort_list-Write a function that sorts a double linke
 * @list:list of linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int sorted = 0;

	listint_t *curr = *list;

	if (!list || !*list || len_size(*list) < 2)
		return;

	while (!sorted)
	{
		sorted = 1;
		while (curr->next)
		{
			if (curr->n > curr->next->n)
			{
				sorted = 0;
				support_list(list, &curr);
				print_list(*list);
			}
			else
				curr = curr->next;
		}
		if (sorted)
			break;
		curr = curr->prev;
		while (curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				sorted = 0;
				curr = curr->prev;
				support_list(list, &curr);
				print_list(*list);
			}
			else
				curr = curr->prev;
		}
	}
}

/**
 * support_list-insert list in case node list
 * @list:nodelist
 * @new:application
 */

void support_list(listint_t **list, listint_t **new)
{
	listint_t *one, *two, *three, *four;

	one = (*new)->prev;
	two = *new;
	three = (*new)->next;
	four = (*new)->next->next;

	two->next = four;
	if (four)
		four->prev = two;
	three->next = two;
	three->prev = one;
	if (one)
		one->next = three;
	else
		*list = three;
	two->prev = three;
	*new = three;
}
