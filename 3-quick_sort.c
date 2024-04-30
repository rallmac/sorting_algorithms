#include <stdio.h>
#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the selection sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in array
 */

void quick_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}

		if (min_idx != i)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;

			for (j = 0; j < size; j++)
			{
				if (j > 0)
					printf(", ");
				printf("%d", array[j]);
			}
			printf("\n");
		}
	}
}
