#include "sort.h"

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

void counting_sort(int *array, size_t size)
{
size_t MAX = max_in(array, size), MIN = min_in(array, size);
int *count_arr = (int*)malloc((MAX - MIN + 1) * sizeof(int));
int *output_arr = (int*)malloc(size * sizeof(int));
size_t i = 0;

/* Initialize count_arr with zeros */
for (i = 0; i < MAX - MIN + 1; i++)
{
count_arr[i] = 0;
}

/* count items */
i = 0;
while (i < size)
{
count_arr[array[i] - MIN] += 1;
i++;
}

/* add prev value to each item */
i = 1;
while (i < MAX - MIN + 1)
{
count_arr[i] += count_arr[i - 1];
printf("%d", count_arr[i]);
if (i < MAX - MIN)
printf(", ");
i++;
}
printf("\n");

/* move items to the correct position in the output array */
i = size;
while (i > 0)
{
output_arr[count_arr[array[i - 1] - MIN] - 1] = array[i - 1];
count_arr[array[i - 1] - MIN] -= 1;
i--;
}

/* copy sorted elements back to the original array */
for (i = 0; i < size; i++)
{
array[i] = output_arr[i];
}

free(count_arr);
free(output_arr);
}
