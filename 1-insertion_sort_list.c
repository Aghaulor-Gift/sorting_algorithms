#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 *			ascending order using the Insertion sort algorithm.
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	return;

	current = (*list)->next;

	while (current != NULL)
	{
	listint_t *temp = current->prev;

	while (temp != NULL && temp->n > current->n)
	{

	if (temp->prev != NULL)
	temp->prev->next = current;
	else
	*list = current;

	if (current->next != NULL)
	current->next->prev = temp;

	temp->next = current->next;
	current->prev = temp->prev;
	temp->prev = current;
	current->next = temp;

	temp = current->prev;
	print_list(*list);
	}

	current = current->next;
	}
}
