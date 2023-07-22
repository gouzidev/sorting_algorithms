#include "sort.h"

/**
 * swap_arr - Swaps two integer values using pointers.
 *
 * @EL_1: A pointer to the first integer to be swapped.
 * @EL_2: A pointer to the second integer to be swapped.
 */

void swap_arr(int *EL_1, int *EL_2)
{
int temp = *EL_1;
*EL_1 = *EL_2;
*EL_2 = temp;
}

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

/**
 * shell_sort - Sorts an array of integers in
 *  ascending order using the Shell sort algorithm.
 *
 * @array: A pointer to the first element
 *  of the array to be sorted.
 * @size: The number of elements in the array.
 * Return: nothing
 */

void shell_sort(int *array, size_t size)
{
size_t gap = 1;

/*init the gap value*/
while (gap < size)
gap = gap * 3 + 1;
gap = (gap - 1) / 3;
/**/
while (gap >= 1)
{
insertion_sort_arr(array, size, gap);
gap = (gap - 1) / 3;
}
}
