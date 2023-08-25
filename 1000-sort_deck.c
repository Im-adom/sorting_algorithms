#include "deck.h"
/**
*swap - this swaps 2 nodes in a doubly-linked list.
*@x: address of first node.
*@y: address of second node.
*Return: nothing
*/
void swap(deck_node_t *x, deck_node_t *y)
{
	if (x->prev)
		x->prev->next = y;
	if (y->next)
		y->next->prev = x;
	x->next = y->next;
	y->prev = x->prev;
	x->prev = y;
	y->next = x;
}
/**
* lessthan - this checks and tells the comparison order between two cards.
* @c: pointer of the first card.
* @d: pointer of the second card.
* Return: true if c > d
*/
int lessthan(const card_t *c, const card_t *d)
{
	char *s1, *s2, *values[] = {"King", "Queen", "Jack", "10", "9", "8",
		"7", "6", "5", "4", "3", "2", "Ace"};
	int val_c = 0, val_d = 0, x = 0;

	for (x = 0; x < 13; x++)
	{
		for (s1 = (char *)c->value, s2 = values[x]; *s1 && *s1 == *s2; ++s1, ++s2)
			;
		if (*s1 == 0 && *s2 == 0)
		{
			val_c = x;
			break;
		}
	}
	for (x = 0; x < 13; x++)
	{
		for (s1 = (char *)d->value, s2 = values[x]; *s1 && *s1 == *s2; ++s1, ++s2)
			;
		if (*s1 == 0 && *s2 == 0)
		{
			val_d = x;
			break;
		}
	}
	if (c->kind == d->kind)
	{
		return (val_c < val_d);
	}
	return (c->kind > d->kind);
}


/**
 * insertion_sort_list - insertion sorts a doubly-linked list
 * @list: the address of pointer to head node.
 * Return: nothing
 */
void insertion_sort_list(deck_node_t **list)
{
	deck_node_t *f, *g;

	if (!list || !*list || !(*list)->next)
		return;
	f = (*list)->next;
	while (f)
	{
		g = f;
		f = f->next;
		while (g && g->prev)
		{
			if (lessthan(g->prev->card, g->card))
			{
				swap(g->prev, g);
				if (!g->prev)
					*list = g;
			}
			else
				g = g->prev;
		}

	}
}
/**
* sort_deck - this sorts the deck using a given sort function.
* @deck: address to pointer of head.
*/
void sort_deck(deck_node_t **deck)
{
	insertion_sort_list(deck);
}
