#include "sort.h"

/**
 * swap - Swaps the integers in ascending order
 * @x: the highest int
 * @y: the lowest int
 *
 * Return: No return
 */

void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * selection_sort - sorts an array of integers in ascending order using the
 * selection sort algorithm
 * @array: an array of integers
 * @size: the size of the array
 *
 * Return: no return
 */

void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap(array + i, min);
			print_array(array, size);
		}
	}
}
