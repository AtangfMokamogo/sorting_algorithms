#include "sort.h"

/**
  * quick_sort -  implements the quick sort algorithm
  * @array: the unsorted array
  * @size: size of @array
  *
  * Description: sorts an array using quick sort in ascending order
  * Return: void
  */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	q_sort(array, 0, size - 1, size);
}


/**
  * partitioner - implements the Lomuto partitioning
  * @array: array to be partionend
  * @low: lower bound
  * @high: upper bound
  * @size: size of @array
  *
  * Description: the Lomuto partitioning scheme is used here
  * Return: the pivot
  */
int partitioner(int *array, int low, int high, size_t size)
{
	int i = low - 1, j = low;
	int pivot = array[high], temp = 0;

	for (; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}


/**
  * q_sort - sorts an array using quick sort algorithm
  * @array: unsorted array
  * @high: upper bound
  * @low: lower bound
  * @size: size of @array
  *
  * Description: sorts an array using quick sort
  * Return: void
  */
void q_sort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partitioner(array, low, high, size);
		q_sort(array, low, pivot - 1, size);
		q_sort(array, pivot + 1, high, size);
	}
}
