#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer sorted in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
*/

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

int _putchar(char c);
void print_array(int *array, size_t size);
void print_list(const listint_t *list);
void swap_nodes(listint_t *a, listint_t *b, listint_t **list);
void swap(int *a, int *b);
void node_swap(listint_t **list, listint_t *node1, listint_t *node2);
int partition(int *array, int low, int high);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_helper(int *array, int low, int high);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif
