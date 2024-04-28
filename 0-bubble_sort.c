#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - bubble function
 * @array: The array input
 * @size: The size of input
 * Return: Always 0
*/
void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}
