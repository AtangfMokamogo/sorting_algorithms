#include "sort.h"

/**
 * shell_sort - implements the Shell sort algorithm
 * @array: the array to sort
 * @size: the size @array
 *
 * Description: sort ann array in ascending order
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	int temp;
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;
	/* Determine the starting gap */
	gap = 1;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	/* Sort the array using the Shell sort algorithm */
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];

			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}

		gap = (gap - 1) / 3;

		/* Print the array after each decrease of the gap */
		print_array(array, size);
	}
}
