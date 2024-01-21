#include "sort.h"

/**
 * selection_sort - sorts an array of integers with
 *                  Selection sort algorithm
 * @array: given integers
 * @size: size of array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
        size_t i, j, tmpI;
        int tmp;

        if (!array || size < 2)
                return;

        for (i = 0; i < size - 1; i++)
        {
                tmp = array[i];
                tmpI = i;

                for (j = i; j < size; j++)
                {
                        if (tmp > array[j])
                        {
                                tmp = array[j];
                                tmpI = j;
                        }
                }
                array[tmpI] = array[i];
                array[i] = tmp;

                print_array(array, size);
        }
}
