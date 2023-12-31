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
int current, current_index;

while (i < size)
{
current = arr[i];
current_index = i;
j = i;

while (j >= gap && arr[j - gap] > current)
{
arr[j] = arr[j - gap];
current_index = j - gap;
j -= gap;
}

arr[current_index] = current;
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
print_array(array, size);
gap = (gap - 1) / 3;
}
}
