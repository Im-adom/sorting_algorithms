#include <stdlib.h>
#include "sort.h"
/**
 * count_sort_2 - radix sort variation that sorts an array of integers
 * based on their lsd
 * @array: array to be sorted
 * @buff:  buffer
 * @size: size
 * @lsd: least significant digit
 */
void count_sort_2(int *array, int **buff, int size, int lsd)
{
	int i, j, count_size = 10, num;
	int num_count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int buff_idx[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (i = 0; i < size; i++)
	{
		num = array[i];
		for (j = 0; j < lsd; j++)
			if (j > 0)
				num = num / 10;
		num = num % 10;
		buff[num][num_count[num]] = array[i];
		num_count[num] += 1;
	}

	for (i = 0, j = 0; i < count_size; i++)
	{
		while (num_count[i] > 0)
		{
			array[j] = buff[i][buff_idx[i]];
			buff_idx[i] += 1, num_count[i] -= 1;
			j++;
		}
	}

	print_array(array, size);
}
/**
 * count_sort - radix sort variation that sorts an array based on
 * their lsd
 * @array: array to be sorted
 * @size: size
 * @lsd: least significant digit
 */
void count_sort(int *array, int size, int lsd)
{
	int num_count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int i, j, num, count_size = 10, **buff;

	for (i = 0; i < size; i++)
	{
		num = array[i];
		for (j = 0; j < lsd; j++)
			if (j > 0)
				num = num / 10;
		num = num % 10;
		num_count[num] += 1;
	}

	if (num_count[0] == size)
		return;

	buff = malloc(sizeof(int *) * 10);
	if (!buff)
		return;

	for (i = 0; i < count_size; i++)
		if (num_count[i] != 0)
			buff[i] = malloc(sizeof(int) * num_count[i]);


	count_sort_2(array, buff, size, lsd);

	count_sort(array, size, lsd + 1);

	for (i = 0; i < count_size; i++)
		if (num_count[i] > 0)
			free(buff[i]);
	free(buff);
}
/**
 * radix_sort - sorts an array of integers in ascending order using the Radix
 * sort algorithm
 * @array: array to be sorted
 * @size: size
 */
void radix_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	count_sort(array, size, 1);
}
