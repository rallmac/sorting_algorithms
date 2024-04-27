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
    size_t i, j, k;
    
    for (i = 0; i < size -1; i++)
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
        for (k = 0; k < size; k++)
        {
            printf("%d", array[k]);
            if (k < size - 1)
            {
                printf(", ");
            }
        }
        printf("\n");
    }
}