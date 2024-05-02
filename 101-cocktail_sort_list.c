#include <stdio.h>
#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list in ascending
 * order using the Cocktail shaker sort algorithm
 *
 * @list: Pointer to the pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *ptr;

	if (list == NULL || *list == NULL)
		return;

	do {
		swapped = 0;
		for (ptr = *list; ptr->next != NULL; ptr = ptr->next)
		{
			if (ptr->n > ptr->next->n)
			{
				node_swap(list, ptr, ptr->next);
				print_list(*list);
				swapped = 1;
			}
		}
		if (!swapped)
			break;

		swapped = 0;

		for (; ptr != NULL && ptr->prev != NULL; ptr = ptr->prev)
		{
			if (ptr->n < ptr->prev->n)
			{
				node_swap(list, ptr->prev, ptr);
				print_list(*list);
				swapped = 1;
			}
		}
	} while (swapped);
}

/**
 * node_swap - Swaps two nodes in a doubly linked list
 *
 * @list: Pointer to the pointer to the head of the list
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void node_swap(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;

	node1->prev = node2;
	node2->next = node1;
}

