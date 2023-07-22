#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly
 *      linked list of integers in ascending order
 *      using the insertion sort algorithm.
 *
 * @list: A pointer to a pointer to the
 *      head of the doubly linked list.
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
listint_t *curr, *tmp;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

curr = (*list)->next;

while (curr != NULL)
{
tmp = curr->next;
/*backwards*/
while (curr->prev != NULL && curr->n < curr->prev->n)
{
curr->prev->next = curr->next;
if (curr->next != NULL)
curr->next->prev = curr->prev;

curr->next = curr->prev;
curr->prev = curr->next->prev;
curr->next->prev = curr;

if (curr->prev == NULL)
*list = curr;
else
curr->prev->next = curr;

print_list(*list);
}
curr = tmp;
}
}
