#include "sort.h"


/**
 * counting_sort - sorts an array of integers in ascending order using
 * the Counting sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	int i, j, max = 0;
	int *count = calloc(1, sizeof(int) * (max + 1));
	int *output = malloc(sizeof(int) * size);

	if (!array || size < 2 || !count || !output)
		goto free_and_exit;

	for (i = 0; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];

	for (i = 0; i < (int)size; i++)
		++count[array[i]];

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	for (j = size - 1; j >= 0; j--)
		output[--count[array[j]]] = array[j];

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

free_and_exit:
	free(output);
	free(count);
}
