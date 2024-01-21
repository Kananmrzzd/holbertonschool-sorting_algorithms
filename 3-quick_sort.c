#include "sort.h"

void swap(int *x, int *y);
int div(int *array, size_t size, int back, int end);
void sort(int *array, size_t size, int back, int end);

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
 * div - order a subset.
 *
 * @array: The array of integers.
 * @size: The size of the array.
 * @back: The starting index of the subset to order.
 * @end: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int div(int *array, size_t size, int back, int end)
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
		swap(array + above, pvt);
		print_array(array, size);
	}

	return (above);
}

/**
 * sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @back: The starting index of the array partition to order.
 * @end: The ending index of the array partition to order.
 *
 * Description: uses the Lomuto partition scheme
 */
void sort(int *array, size_t size, int back, int end)
{
	int a;

	if (end > back)
	{
		a = div(array, size, back, end);
		sort(array, size, back, a - 1);
		sort(array, size, a + 1, end);
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

	sort(array, size, 0, size - 1);
}
