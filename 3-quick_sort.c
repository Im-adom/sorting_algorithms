#include "sort.h"

/**
 * swap - swaps elements in an array.
 * @array: array to be modified.
 * @left: The index of the left item.
 * @right: The index of the right item.
 */
void swap(int *array, size_t left, size_t right)
{
	int temp;

	if (array != NULL)
	{
		temp = array[left];
		array[left] = array[right];
		array[right] = temp;
	}
}

/**
 * quick_sort_range_lomuto - Sorts a sub array using the
 * quick sort algorithm and Lomuto's partition scheme.
 * @array: The array containing the sub-array.
 * @low: The starting position of the sub-array.
 * @high: The ending position of the sub-array.
 * @size: The length of the array.
 */
void quick_sort_range_lomuto(int *array, size_t low, size_t high, size_t size)
{
	size_t before, after;
	int pivot;

	if ((low >= high) || (array == NULL))
		return;
	pivot = array[high];
	before = low;
	for (after = low; after < high; after++)
	{
		if (array[after] <= pivot)
		{
			if (before != after)
			{
				swap(array, before, after);
				print_array(array, size);
			}
			before++;
		}
	}
	if (before != high)
	{
		swap(array, before, high);
		print_array(array, size);
	}
	if (before - low > 1)
		quick_sort_range_lomuto(array, low, before - 1, size);
	if (high - before > 1)
		quick_sort_range_lomuto(array, before + 1, high, size);
}

/**
 * quick_sort - Sorts an array using the quick sort algorithm
 * and Lomuto's partition scheme.
 * @array: The array to sort.
 * @size: The length of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		quick_sort_range_lomuto(array, 0, size - 1, size);
	}
}
