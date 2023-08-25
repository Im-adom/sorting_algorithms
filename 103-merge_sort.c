#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * data_copy - copies data from one buffer to another
 * @src: source buffer
 * @dst: destination buffer
 * @size: size of buffers
 */
void data_copy(int *src, int *dst, int size)
{
	int i;

	for (i = 0; i < size; i++)
		dst[i] = src[i];
}
/**
 * data_merge - merges two sets of sorted data in ascending order
 * @array: first set of data
 * @buff: second set of data
 * @minL: first lower range
 * @maxL: first upper range
 * @minR: second lower range
 * @maxR: second upper range
 */
void data_merge(int *array, int *buff, int minL, int maxL, int minR, int maxR)
{
	int i = minL, j = minR, k = minL;

	while (i <= maxL || j <= maxR)

		if (i <= maxL && j <= maxR)
			if (buff[i] <= buff[j])
				array[k] = buff[i], k++, i++;
			else
				array[k] = buff[j], k++, j++;

		else if (i > maxL && j <= maxR)
			array[k] = buff[j], k++, j++;
		else
			array[k] = buff[i], k++, i++;
}
/**
 * print_data - prints an array in a given range
 * @array: array of data to be print
 * @s1: start of range
 * @s2: end of range
 */
void print_data(int *array, int s1, int s2)
{
	int i;

	for (i = s1; i <= s2; i++)
	{
		if (i > s1)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}
/**
 * split_data - split data into merge tree
 * @array: array of data to be split
 * @buff: auxiliary array of data for merging
 * @min: min range
 * @max: max range
 * @size: size of data
 */
void split_data(int *array, int *buff, int min, int max, int size)
{
	int mid, tmax, minL, maxL, minR, maxR;

	if ((max - min) <= 0)
		return;

	mid = (max + min + 1) / 2;
	tmax = max;
	max = mid - 1;

	minL = min;
	maxL = max;

	split_data(array, buff, min, max, size);

	min = mid;
	max = tmax;

	minR = min;
	maxR = max;

	split_data(array, buff, min, max, size);

	printf("Merging...\n");
	printf("[left]: ");

	print_data(array, minL, maxL);

	printf("[right]: ");

	print_data(array, minR, maxR);
	data_merge_sorted(array, buff, minL, maxL, minR, maxR);
	data_copy(array, buff, size);

	printf("[Done]: ");
	print_data(array, minL, maxR);
}
/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: array to be used
 * @size: size of data
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	data_copy(array, temp, size);

	split_data(array, temp, 0, size - 1, size);

	free(temp);
}
