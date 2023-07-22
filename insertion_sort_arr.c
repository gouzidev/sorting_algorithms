#include "sort.h"

/**
 * insertion_sort_arr - Sorts a subarray of integers
 *      using the insertion sort algorithm.
 *
 * @arr: A pointer to the first element of the
 *      subarray to be sorted.
 * @size: The number of elements in the subarray.
 * @gap: The gap value used for sorting elements
 *      that are far apart.
 * Return: nothing
 */

void insertion_sort_arr(int *arr, size_t size, size_t gap)
{
size_t i = gap, j;

while (i < size)
{
j = i;
while (j >= gap)
{
if (arr[j - gap] > arr[i])
swap_arr(&arr[j - gap], &arr[i]);
j -= gap;
}
i++;
}
}
