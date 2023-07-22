#include "sort.h"

/**
 * bubble_sort - bubble sorts array
 * @array: list of integers
 * @size: size of the list of integers
 * Return: void
*/
void bubble_sort(int *array, size_t size)
{
size_t i = 0;
size_t j = 0;
int tmp;

if (size < 2 || array == NULL)
return;
while (i < size)
{
j = 0;
while (j < size - 1)
{
if (array[j] > array[j + 1])
{
tmp = array[j];
array[j] = array[j + 1];
array[j + 1] = tmp;
print_array(array, size);
}
j++;
}
i++;
}
}
