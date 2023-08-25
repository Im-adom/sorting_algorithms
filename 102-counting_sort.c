#include "sort.h"
/**
 * get_max - This gets the maximum value in an array of integers.
 * @array: the array of integers.
 * @size: size of the array.
 * Return: the maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int maxi, m;

	for (maxi = array[0], m = 1; m < size; m++)
	{
		if (array[m] > maxi)
			maxi = array[m];
	}
	return (maxi);
}
/**
 * counting_sort - Implementation of the counting sort algorithm.
 * @array: the array of integers.
 * @size: size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, maxi, m;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	maxi = get_max(array, size);
	count = malloc(sizeof(int) * (maxi + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (m = 0; m < (maxi + 1); m++)
		count[m] = 0;
	for (m = 0; m < (int)size; m++)
		count[array[m]] += 1;
	for (m = 0; m < (maxi + 1); m++)
		count[m] += count[m - 1];
	print_array(count, maxi + 1);

	for (m = 0; m < (int)size; m++)
	{
		sorted[count[array[m]] - 1] = array[m];
		count[array[m]] -= 1;
	}

	for (m = 0; m < (int)size; m++)
		array[m] = sorted[m];

	free(sorted);
	free(count);
}
