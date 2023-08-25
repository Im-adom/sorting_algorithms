#include "sort.h"
/**
 * locate_min - This locates the min from the
 * current index in the array.
 * @array: the array to be searched.
 * @index: the start index of the search.
 * @size: size of the array
 * Return: the index of min if found or
 * same index if that index is the min.
 */
int locate_min(int *array, int index, size_t size)
{
	int min, min_index;
	int g;

	min = array[index];
	min_index = index;
	for (g = index; g < (int)size; g++)
	{
		if (array[g] < min)
		{
			min = array[g];
			min_index = g;
		}
	}
	if (min_index == index)
		return (-1);
	return (min_index);
}
/**
 * selection_sort - Implements the selection sort algorithm.
 * @array: the array to sort.
 * @size: size of the array.
 * Return: the sorted array.
 */
void selection_sort(int *array, size_t size)
{
	int g;
	int min, temp;

	for (g = 0; g < (int)size; g++)
	{
		min = locate_min(array, g, size);
		if (min != -1)
		{
			temp = array[g];
			array[g] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
