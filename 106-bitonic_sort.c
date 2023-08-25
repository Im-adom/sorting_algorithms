#include <stdio.h>
#include "sort.h"
/**
 * swap - this swaps 2 integer values.
 * @x: address of first value.
 * @y: address of second value.
 * Return: nothing
 */
void swap(int *x, int *y)
{
	if (*x != *y)
	{
		*x = *x + *y;
		*y = *x - *y;
		*x = *x - *y;
	}
}
/**
 * comp_bitonic - this compares bitonically.
 * @up: true if UP sorting.
 * @array: pointer to the array.
 * @start: the start index.
 * @end: the stop index.
 */
void comp_bitonic(int up, int *array, size_t start, size_t end)
{
	size_t h = (end - start + 1) / 2, g;

	for (g = start; g < start + h; g++)
		if ((array[g] > array[g + h]) == up)
			swap(&array[g], &array[g + h]);
}
/**
 * merge_bitonic - this merges bitonically.
 * @up: true if UP sorting.
 * @array: the pointer to the array.
 * @start: the start index.
 * @end: the stop index.
 */
void merge_bitonic(int up, int *array, size_t start, size_t end)
{
	size_t m = (start + end) / 2;

	if (end - start < 1)
		return;
	comp_bitonic(up, array, start, end);
	merge_bitonic(up, array, start, m);
	merge_bitonic(up, array, m + 1, end);
}
/**
 * sort_bitonic - this sorts bitonically using recursion.
 * @up: true if UP sorting
 * @array: the pointer to the array.
 * @size: the length of the array.
 * @start: the start index.
 * @end: the stop index.
 */
void sort_bitonic(int up, int *array, size_t size, size_t start, size_t end)
{
	size_t m = (start + end) / 2;

	if (end - start < 1)
		return;
	printf("Merging [%lu/%lu] (%s):\n", end - start + 1, size,
		up ? "UP" : "DOWN");
	print_array(array + start, end - start + 1);
	sort_bitonic(1, array, size, start, m);
	sort_bitonic(0, array, size, m + 1, end);
	merge_bitonic(up, array, start, end);
	printf("Result [%lu/%lu] (%s):\n", end - start + 1, size,
		up ? "UP" : "DOWN");
	print_array(array + start, end - start + 1);
}
/**
 * bitonic_sort - Implementation of bitonic sort algorithm.
 * @array: the pointer to the array.
 * @size: the length of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	sort_bitonic(1, array, size, 0, size - 1);
}
