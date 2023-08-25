#include "sort.h"
/**
 * shell_sort - Implemetation of shell sort algorithm using Knuth sequence.
 * @array: the array to be sorted.
 * @size: size of the array.
 * Return: the sorted array.
 */
void shell_sort(int *array, size_t size)
{
	int n = 1, f, g;
	int temp;

	if (!array || !size || size < 2)
		return;
	while (n < (int)size / 3)
		n = n * 3 + 1;
	while (n > 0)
	{
		for (f = n; f < (int)size; f++)
		{
			temp = array[f];
			g = f;
			while (g > (n - 1) && array[g - n] >= temp)
			{
				array[g] = array[g - n];
				g -= n;
			}
			array[g] = temp;
		}
		n = n / 3;
		print_array(array, size);
	}
}
