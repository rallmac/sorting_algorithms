#include <stdio.h>
#include "sort.h"

/**
 * lomuto_partition - Partitions an array using Lomuto partition scheme
 * @array: The array to be partitioned
 * @low: Starting index of the array
 * @high: Ending index of the array
 * Return: Index of the pivot element
 */
size_t lomuto_partition(int *array, size_t low, size_t high)
{
	int pivot = array[high];
	int temp;
	size_t i = low - 1;
	size_t j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;

	return i + 1;
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the quick sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in array
 */
void quick_sort(int *array, size_t size)
{
	size_t pivot_index;
	size_t i;
	
	if (size <= 1)
		return;
	
	pivot_index = lomuto_partition(array, 0, size - 1);

	if (pivot_index > 0)
	{
		quick_sort(array, pivot_index);
	}
	
	quick_sort(array + pivot_index + 1, size - pivot_index - 1);
	for (i = 0; i < size; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}
