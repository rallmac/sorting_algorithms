#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the insertion sort algorithm
 *
 * @list: Pointer to the pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;
	int value;
	
	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		temp = current->prev;
		value = current->n;

		while (temp && temp->n > value)
		{
			swap_nodes(temp, current, list);
			print_list(*list);
			temp = current->prev;
		}

		current = current->next;
	}
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @a: pointer to the first node
 * @b: Pointer to the second node
 * @list: Pointer to the pointer to the head of the list
 */
void swap_nodes(listint_t *a, listint_t *b, listint_t **list)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;

	if (!b->prev)
		*list = b;
}
