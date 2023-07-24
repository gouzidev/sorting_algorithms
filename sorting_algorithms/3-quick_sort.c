#include "sort.h"

/**
 * swap - Swaps the values of two integer pointers.
 *
 * @a: A pointer to an integer.
 * @b: A pointer to another integer.
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * partition - Partitions the array into two
 * subarrays around a pivot element.
 * 
 * @array: A pointer to the array to be sorted.
 * @size: The size of the array.
 * @low: The index of the first element
 * of the partition being sorted.
 * @high: The index of the last element
 * of the partition being sorted.
 *
 * Return: The index of the pivot
 * element after partitioning.
 */
int partition(int *array, size_t size, int low, int high)
{
    int pivot = array[high];
    int i = low - 1, j = low;

    while (j < high)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
        j++;
    }

    swap(&array[i + 1], &array[high]);
    print_array(array, size);

    return (i + 1);
}

/**
 * quick_sort_rec - Recursive function to perform
 * Quick sort on the array.
 *
 * @array: A pointer to the array to be sorted.
 * @size: The size of the array.
 * @low: The index of the first element
 * @high: The index of the last element
 */
void quick_sort_rec(int *array, size_t size, int low, int high)
{
    if (low < high)
    {
        int p_i = partition(array, size, low, high);

        quick_sort_rec(array, size, low, p_i - 1);
        quick_sort_rec(array, size, p_i + 1, high);
    }
}

/**
 * quick_sort - Sorts an array of integers
 * in ascending order using the Quick sort algorithm.
 *
 * @array: A pointer to the array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
    quick_sort_rec(array, size, 0, size - 1);
}