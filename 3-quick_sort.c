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
	i = back;
	j = end;
	pvt = array[j];
	
	do
	{
		while (array[i] < pvt)
			i++;
		while (array[j] > pvt)
			j--;

		if (i <= j)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			i++;
			j--;
			print_array(array, size);
		}

	}while (i <= j);

	if (i < end)
		rec(array, i, end, size);

	if(back < j)
		rec(array, back , j, size);
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
