#include "sort.h"
#include <stddef.h>
/**
 * bubble_sort - sorting array
 * @array: array
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, swap, j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap = array[j];
				array[j] = array[j + 1];
				array[j + 1] = swap;
			}
			print_array(array, size);
		}
	}
}
