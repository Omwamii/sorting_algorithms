#include "deck.h"

int val(const char *str);
/**
 * sort_deck - sorts a deck of cards using insertion sort
 * @deck: ptr to deck list header
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *curr, *prev, *next;

	if (deck == NULL || (*deck)->next == NULL)
		return;

	curr = *deck;
	while (curr)
	{
		prev = curr->prev;
		next = curr->next;
		if (prev && curr->card->kind <= prev->card->kind)
		{
			if (val(curr->card->value) == -1 ||
					val(prev->card->value) == -1)
				return;
			if (curr->card->kind == prev->card->kind)
			{
				if (val(curr->card->value) > val(prev->card->value))
				{
					curr = curr->next;
					continue;
				}
			}
			if (prev->prev == NULL)
				*deck = curr;
			if (prev->prev != NULL)
				curr->prev->prev->next = curr;
			curr->prev = prev->prev;
			curr->next = prev;
			prev->prev = curr;
			prev->next = next;
			if (next != NULL)
				next->prev = prev;
		}
		else
			curr = curr->next;
	}
}

/**
 * val - find value of card based on string
 * @str: value string
 *
 * Return: integer value of card or -1 if invalid
 */
int val(const char *str)
{
	int val;

	if (strlen(str) <= 2)
	{
		val  = atoi(str);
		if (val > 10)
			return (-1);
		return (val);
	}
	else
	{
		if (strcmp(str, "Ace") == 0)
			return (1);
		else if (strcmp(str, "Jack") == 0)
			return (11);
		else if (strcmp(str, "Queen") == 0)
			return (12);
		else if (strcmp(str, "King") == 0)
			return (13);
		else
			return (-1);
	}
}
