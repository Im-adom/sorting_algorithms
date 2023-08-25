#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - sorts an array of integers in ascending order
 *
 * @array: array of integers
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
    size_t pass_out, current_in;
    int temp;

    if (!array || size == 0)
        return;

    for (pass_out = 0; pass_out < size - 1; pass_out++)
    {
        for (current_in = 0; current_in < size - pass_out - 1; current_in++)
        {
            if (array[current_in] > array[current_in + 1])
            {
                temp = array[current_in];
                array[current_in] = array[current_in + 1];
                array[current_in + 1] = temp;
                print_array(array, size);
            }
        }
    }
}

