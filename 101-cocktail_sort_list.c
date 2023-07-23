#include "sort.h"

void swap_front(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_back(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_front - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_front(listint_t **list, listint_t **tail, listint_t **shaker)
{
listint_t *curr = (*shaker)->next;

if ((*shaker)->prev != NULL)
(*shaker)->prev->next = curr;
else
*list = curr;
curr->prev = (*shaker)->prev;
(*shaker)->next = curr->next;
if (curr->next != NULL)
curr->next->prev = *shaker;
else
*tail = *shaker;
(*shaker)->prev = curr;
curr->next = *shaker;
*shaker = curr;
}

/**
* swap_back - Swap a node in a listint_t doubly-linked
*                    list of integers with the node behind it.
* @list: A pointer to the head of a doubly-linked list of integers.
* @tail: A pointer to the tail of the doubly-linked list.
* @shaker: A pointer to the current swapping node of the cocktail shaker algo.
*/
void swap_back(listint_t **list, listint_t **tail, listint_t **shaker)
{
listint_t *curr = (*shaker)->prev;

if ((*shaker)->next != NULL)
(*shaker)->next->prev = curr;
else
*tail = curr;
curr->next = (*shaker)->next;
(*shaker)->prev = curr->prev;
if (curr->prev != NULL)
curr->prev->next = *shaker;
else
*list = *shaker;
(*shaker)->next = curr;
curr->prev = *shaker;
*shaker = curr;
}

/**
* cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
*                      ascending order using the cocktail shaker algorithm.
* @list: A pointer to the head of a listint_t doubly-linked list.
*/
void cocktail_sort_list(listint_t **list)
{
listint_t *tail, *shaker;
int shaken_not_stirred = 0;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

tail = *list;
while (tail->next != NULL)
tail = tail->next;

while (shaken_not_stirred == 0)
{
shaken_not_stirred = 1;
shaker = *list;
while (shaker != tail)
{
if (shaker->n > shaker->next->n)
{
swap_front(list, &tail, &shaker);
print_list((const listint_t *)*list);
shaken_not_stirred = 0;
}
shaker = shaker->next;
}
shaker = shaker->prev;
while (shaker != *list)
{
if (shaker->n < shaker->prev->n)
{
swap_back(list, &tail, &shaker);
print_list((const listint_t *)*list);
shaken_not_stirred = 0;
}
shaker = shaker->prev;
}
}
}
