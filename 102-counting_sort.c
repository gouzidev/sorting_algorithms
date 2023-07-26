#include "sort.h"

/**
 * max_in - Find the maximum value in an integer array.
 * @array: The input integer array.
 * @size: The size of the array.
 *
 * Return: The maximum value in the array.
 */
size_t max_in(int *array, size_t size)
{
size_t i = 0;
int max = array[0];

while (i < size)
{
if (array[i] > max)
max = array[i];
i++;
}

return max;
}

/**
* min_in - Find the minimum value in an integer array.
* @array: The input integer array.
* @size: The size of the array.
*
* Return: The minimum value in the array.
*/
size_t min_in(int *array, size_t size)
{
size_t i = 0;
int min = array[0];

while (i < size)
{
if (array[i] < min)
min = array[i];
i++;
}

return min;
}

/**
* counting_sort - Sorts an array of integers in
* ascending order using counting sort.
* @array: The input integer array to be sorted.
* @size: The size of the array.
*/
void counting_sort(int *array, size_t size)
{
size_t MAX = max_in(array, size),
MIN = min_in(array, size);
int *count_arr = malloc((MAX - MIN + 1) * sizeof(int));
int *output_arr = malloc(size * sizeof(int));
size_t i = 0;

/* Initialize count_arr with zeros */
for (i = 0; i < MAX - MIN + 1; i++)
{
count_arr[i] = 0;
}

/* Count occurrences of each element */
i = 0;
while (i < size)
{
count_arr[array[i] - MIN] += 1;
i++;
}

/* Calculate cumulative sum for counting positions */
i = 1;
while (i < MAX - MIN + 1)
{
count_arr[i] += count_arr[i - 1];
i++;
}

/* Move items to the correct position in the output array */
i = size;
while (i > 0)
{
output_arr[count_arr[array[i - 1] - MIN] - 1] = array[i - 1];
count_arr[array[i - 1] - MIN] -= 1;
i--;
}

/* Copy sorted elements back to the original array */
for (i = 0; i < size; i++)
{
array[i] = output_arr[i];
}

free(count_arr);
free(output_arr);
}
