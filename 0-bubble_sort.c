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
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 *
 * Return: no return
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (array == NULL || array < 2)
		return;

	for (i = 0; i < (size - 1); i++)
	{
		for (j = 0; j < (size - 1 - i); j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
