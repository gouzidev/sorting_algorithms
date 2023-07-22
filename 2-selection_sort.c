#include "sort.h"


/**
 * selection_sort - sorts
 *
 * @array: array
 * @size: array size
 */

void selection_sort(int *array, size_t size)
{
size_t i = 0;
size_t j = 0;
int min;
size_t min_idx;
int tmp;

if (array == NULL || size < 2)
return;
while (i < size)
{
min = array[i];
j = i;
min_idx = i;
while (j < size)
{
if (min > array[j])
{
min = array[j];
min_idx = j;
}
j++;
}
if (min_idx + 1 == i || min_idx == i)
{
i++;
continue;
}
tmp = array[i];
array[min_idx] = tmp;
array[i] = min;
i++;
print_array(array, size);
}
}
