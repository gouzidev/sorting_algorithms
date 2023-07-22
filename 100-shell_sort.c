#include "sort.h"

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
int i = 0;

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
