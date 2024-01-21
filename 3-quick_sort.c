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
	j = back;

	for (i = back; i < end; i++)
	{
		if (array[i] < pvt)
		{
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
			if (array[i] != array[j])
				print_array(array, size);
			j++;
		}
	}

	tmp = array[j];
	array[j] = array[end];
	array[end] = tmp;

	if (array[end] != array[i])
		print_array(array, size);

	if (back < end)
	{
		rec(array, back, j - 1, size);
		rec(array, j + 1, end, size);
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
