#include "sort.h"

/**
 *  insertion_sort_list - sort list using insertion sort
 *  @list: ptr to list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *next, *curr, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = *list;
	while (curr)
	{
		prev = curr->prev;
		next = curr->next;
		if (prev && curr->n < prev->n)
		{
			if (prev->prev == NULL)
				*list = curr;
			if (prev->prev != NULL)
				curr->prev->prev->next = curr;
			curr->prev = prev->prev;
			curr->next = prev;
			prev->prev = curr;
			prev->next = next;
			if (next != NULL)
				next->prev = prev;
			print_list((const listint_t *)*list);
		}
		else
			curr = curr->next;
	}
}

