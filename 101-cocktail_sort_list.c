#include "sort.h"

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
/**
 * cocktail_sort_list - sorts list with cocktailsort algo
 * @list: list head  pointer
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *curr, *tail, *tail_cpy, *next, *prev;
	bool swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = *list;
	while (curr)
		tail_cpy = curr, curr = curr->next;
	while (1)
	{
		curr = *list, tail = tail_cpy, swapped = false;
		while (curr && (curr->next != NULL))
		{
			next = curr->next;
			if (curr->n > next->n)
			{
				swap_nodes(list, curr, next);
				if (curr->next == NULL)
					tail_cpy = curr;
				swapped = true;
				print_list(*list);
			}
			else
				curr = next;
		}
		if (!swapped)
			break;
		swapped = false;
		while (tail && (tail->prev != NULL))
		{
			prev = tail->prev;
			if (tail->n < prev->n)
			{
				swap_nodes(list, prev, tail);
				swapped = true;
				print_list(*list);
			}
			else
				tail = prev;
		}
		if (!swapped)
			break;
	}
}

/**
 * swap_nodes - swaps nodes in a linked list
 * @list: list head pointer
 * @node1: first node
 * @node2: second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	node1->next = node2->next;
	if (node1->next != NULL)
		node1->next->prev = node1;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
	if (node2->prev == NULL)
		*list = node2;
	else
		node2->prev->next = node2;
}
