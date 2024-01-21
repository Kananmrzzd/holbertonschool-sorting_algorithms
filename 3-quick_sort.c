#include "sort.h"

void swap(int *x, int *y);
int part(int *array, size_t size, int back, int end);

/**
 * swap - swap two integers in array
 * @x: first integer to swap
 * @y: second integer to swap
 */
void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * part - order a subset.
 *
 * @array: The array of integers.
 * @size: The size of the array.
 * @back: The starting index of the subset to order.
 * @end: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
void part(int *array, size_t size, int back, int end)
{
	int *pvt, above, below;

	pvt = array + end;
	for (above = below = back; below < end; below++)
	{
		if (array[below] < *pvt)
		{
			if (above < below)
			{
				swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pvt)
	{
		part(array + above, pvt);
		print_array(array, size);
	}

        if (end > back)
        {
                part(array, size, back, above - 1);
                part(array, size, above + 1, end);
        }
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm
 * @array: array of integers
 * @size: size of the array
 *
 * Description: prints the array after each swap of two elements
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	part(array, size, 0, size - 1);
}
