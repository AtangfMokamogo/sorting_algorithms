#include "sort.h"

/**
  * insertion_sort_list - implements insertion sort algorithm
  * @list: the unsorted  doubly-linked list
  *
  * Return: void
  */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	/*check to see if list is empty or sorted*/
	if (!list || !(*list) || !(*list)->next)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current->prev;
		while (temp && temp->n > current->n)
		{
			if (temp->prev != NULL)
				temp->prev->next = current;
			else
				(*list) = current;

			current->prev = temp->prev;
			temp->prev = current;
			temp->next = current->next;

			if (current->next != NULL)
				current->next->prev = temp;
			current->next = temp;
			print_list(*list);

			temp = current->prev;
		}

		current = current->next;
	}
}
