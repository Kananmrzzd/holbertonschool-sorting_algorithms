#include "sort.h"

void rec(int *array, int back, int end, size_t size);
/**
 * rec - recursion for quick sort
 * @back: first index of array
 * @end: last index of array
 *
 * Return: void
 */
void rec(int *array, int back, int end, size_t size)
{
	int pvt, i, j, tmp;

	pvt = array[end];
	
	for (i = back; i < end; i++)
	{
		if (array[i] < pvt)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (array[i] != array[j])
				print_array(array, size);
			j++;
		}
	}

	tmp = array[i];
	array[i] = array[end];
	array[end] = tmp;

	if (array[end] != array[i])
		print_array(array, size);

	if (back < end)
	{
		rec(array, back, i - 1, size);
		rec(array, i + 1, end, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending
 *              order using the Quick sort algorithm
 * @array: integers
 * @size: size of array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	rec(array, 0, (int)size - 1, size);
}
