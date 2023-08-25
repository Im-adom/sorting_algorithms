#include "sort.h"

/**
 * swap_nodes - Swaps two nodes of doubly linked list
 * @node: node base to change
 * @list: pointer to the head of the doubly linked list
 */
void swap_nodes(listint_t **node, listint_t **list)
{
	listint_t *temp = *node, *temp_2, *temp_3;


	if (!(*node)->prev)
		*list = (*node)->next;

	temp = temp_3 = *node;
	temp_2 = temp->next;

	temp->next = temp_2->next;
	temp_3 = temp->prev;
	temp->prev = temp_2;
	temp_2->next = temp;
	temp_2->prev = temp_3;

	if (temp_2->prev)
		temp_2->prev->next = temp_2;


	if (temp->next)
		temp->next->prev = temp;

	*node = temp_2;

}
/**
 * cocktail_sort_list - sorts a doubly linked list
 * of integers in ascending order using the Cocktail shaker sort algorithm
 * @list: pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *aux;
	int c = 0, n = -1, m = -1;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;

	head = *list;
	while (m >= n)
	{
		n++;
		while (head->next && c != m)
		{
			if (head->n > head->next->n)
			{
				aux = head;
			       swap_nodes(&aux, list);
			       print_list(*list);
			       head = aux;
			}

			c++;
			head = head->next;
		}

		if (n == 0)
			m = c;
		m--;
		while (head->prev && c >= n)
		{
			if (head->n < head->prev->n)
			{
				aux = head->prev;
				swap_nodes(&aux, list);
				print_list(*list);
				head = aux->next;
			}
			c--;
			head = head->prev;
		}
	}
}
