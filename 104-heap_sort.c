#include "sort.h"

#define HEAP_PARENT_INDEX(node_index) (((node_index) - 1) / 2)
#define HEAP_CHILD_L_INDEX(node_index) (((node_index) * 2) + 1)
#define HEAP_CHILD_R_INDEX(node_index) (((node_index) * 2) + 2)
/**
 * swap_print - this swap elements and prints the array.
 * @array: pointer to the array.
 * @size: size of the array.
 * @i: index of element to swap
 * @j: index of element to swap
 */
static void swap_print(int *array, size_t size, size_t i, size_t j)
{
	array[i] ^= array[j];
	array[j] ^= array[i];
	array[i] ^= array[j];
	print_array(array, size);
}
/**
 * sift_down -this repairs a max-heap at the parent of valid max-heaps.
 * @array: pointer to the array
 * @size: size of the array
 * @start: index of the root of the heap to repair
 * @end: index of the last heap element
 */
static void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root = start;
	size_t swap = root;
	size_t child_l = 0;
	size_t child_r = 0;

	while (HEAP_CHILD_L_INDEX(root) <= end)
	{
		child_l = HEAP_CHILD_L_INDEX(root);
		child_r = HEAP_CHILD_R_INDEX(root);
		if (array[swap] < array[child_l])
			swap = child_l;
		if (child_r <= end && array[swap] < array[child_r])
			swap = child_r;
		if (swap == root)
			return;
		swap_print(array, size, root, swap);
		root = swap;
	}
}
/**
 * heap_max - This construct a max-heap.
 * @array: pointer to the array.
 * @size: size of the array.
 */
static void heap_max(int *array, size_t size)
{
	size_t end = size - 1;
	size_t start = HEAP_PARENT_INDEX(end);

	while (start < end)
		sift_down(array, size, start--, end);
}
/**
 * heap_sort - this sorts an array in the ascending order.
 * @array: pointer to the array.
 * @size: size of the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t end = size - 1;

	if (array && size)
	{
		heap_max(array, size);
		while (end > 0)
		{
			swap_print(array, size, 0, end--);
			sift_down(array, size, 0, end);
		}
	}
}
