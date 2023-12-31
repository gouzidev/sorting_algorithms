#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
const int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;

/*prints:*/
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

/*helpers*/
void swap_front(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_back(listint_t **list, listint_t **tail, listint_t **shaker);
void insertion_sort_arr(int *arr, size_t size, size_t gap);

/*mand:*/
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);

/*advanced*/
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);

#endif
