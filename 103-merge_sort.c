#include "sort.h"

/**
 * _merge_ - Merge two sorted subarrays into a sorted array.
 * @array: The original array to be sorted.
 * @l_sub: The left subarray.
 * @left_size: The size of the left subarray.
 * @r_sub: The right subarray.
 * @right_size: The size of the right subarray.
 */

void _merge_(int *array, int *l_sub, int left_size, int *r_sub, int right_size)
{
int i = 0, j = 0, k = 0;

while (i < left_size && j < right_size)
{
if (l_sub[i] <= r_sub[j])
{
array[k] = l_sub[i];
i++;
}
else
{
array[k] = r_sub[j];
j++;
}
k++;
}

while (i < left_size)
{
array[k] = l_sub[i];
i++;
k++;
}

while (j < right_size)
{
array[k] = r_sub[j];
j++;
k++;
}
}

/**
 * print_handle - Prints the merging process
 * and the final sorted array.
 *
 * @array: Pointer to the original array to be sorted.
 * @size: The size of the original array.
 * @l_sub: Pointer to the left subarray.
 * @left_size: The size of the left subarray.
 * @r_sub: Pointer to the right subarray.
 * @right_size: The size of the right subarray.
 *
 * Return: None (void).
 */
void print_handle(int *array, size_t size,
	int *l_sub, int left_size,
	int *r_sub, int right_size)
{
int x = 0;
size_t i = 0;

printf("Merging...\n[left]: ");
x = 0;
while (x < left_size)
{
printf("%d", l_sub[x]);
if (x < left_size - 1)
printf(", ");
x++;
}
printf("\n[right]: ");
x = 0;
while (x < right_size)
{
printf("%d", r_sub[x]);
if (x < right_size - 1)
printf(", ");
x++;
}
printf("\n[Done]: ");
i = 0;
while (i < size)
{
printf("%d", array[i]);
if (i < size - 1)
printf(", ");
i++;
}
printf("\n");
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the
 *              Merge sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void merge_sort(int *array, size_t size)
{
int mid = size / 2,
left_size = mid,
right_size = size - mid,
*l_sub = malloc(left_size * sizeof(int)),
*r_sub = malloc(right_size * sizeof(int));
size_t i = 0;
int x = 0;

if (size < 2)
return;
while (x < mid)
{
l_sub[x] = array[x];
x++;
}
i = mid;
while (i < size)
{
r_sub[i - mid] = array[i];
i++;
}
merge_sort(l_sub, left_size);
merge_sort(r_sub, right_size);
_merge_(array, l_sub, left_size, r_sub, right_size);
print_handle(array, size, l_sub, left_size, r_sub, right_size);
free(l_sub);
free(r_sub);
}
