#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted_array;
	int max_element, i;

	max_element = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max_element)
			max_element = array[i];
	}

	count = malloc((max_element + 1) * sizeof(int));
	if (count == NULL)
	{
		printf("Memory allocation failed.\n");
		return;
	}

	for (i = 0; i <= max_element; i++)
		count[i] = 0;

	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	for (i = 0; i <= max_element; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", count[i]);
	}
	printf("\n");

	for (i = 1; i <= max_element; i++)
		count[i] += count[i - 1];

	sorted_array = malloc(size * sizeof(int));
	if (sorted_array == NULL)
	{
		printf("Memory allocation failed.\n");
		free(count);
		return;
	}

	for (i = (int)size - 1; i >= 0; i--)
	{
		sorted_array[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted_array[i];

	free(sorted_array);
	free(count);
}
