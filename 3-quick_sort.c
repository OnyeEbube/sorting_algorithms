#include "sort.h"

/**
 * swap - swaps to elements in an array
 * @x: the highest value
 * @y: the lowest value
 *
 * Return: no return
 */

void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * lomuto_partition - implements the lomuto partition scheme
 * @array: the array to be partitioned
 * @low: the lowest index
 * @high: the highest index
 * @size: the size of the array
 *
 * Return: the partition index
 */

int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot, i, j;

	pivot = array[high];
	i = low;

	for (j = low; j <= high - 1; j++)
	{
		if (pivot >= array[j])
		{
			if (i < j)
			{
				swap(&array[j], &array[i]);
				print_array(array, size);
			}
			i = i + 1;
		}
	}
	if (array[i] > pivot)
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}

/**
 * lomuto_sort - sorts an array using lomuto scheme
 * @low: the lowest index
 * @high: the highest index
 * @array: the array
 * @size: the size of the array
 *
 * Return: no return
 */

void lomuto_sort(int *array, size_t size, int low, int high)
{
	int pi;

	if (low < high)
	{
		pi = lomuto_partition(array, size, low, high);
		lomuto_sort(array, size, low, pi - 1);
		lomuto_sort(array, size, pi + 1, high);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 *
 * Return: no return
 */

void quick_sort(int *array, size_t size)
{

	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
