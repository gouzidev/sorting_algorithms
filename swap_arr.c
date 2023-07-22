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
