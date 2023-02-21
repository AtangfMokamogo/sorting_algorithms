/**
 * cocktail_sort_list - implements the cocktail sort algorithm
 * @list: a pointer to a pointer to the head of the list
 *
 * Description: sorts a Doubly-linked list of ints in ascending order
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *left, *right, *tmp;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	left = *list;
	right = left->next;

	while (swapped == 1)
	{
		swapped = 0;

		/* Move from left to right */
		while (right != NULL)
		{
			if (left->n > right->n)
			{
				/* Swap the nodes */
				if (left->prev != NULL)
					left->prev->next = right;
				right->prev = left->prev;
				right->prev = left->prev;
				left->prev = right;
				left->next = right->next;
				right->next = left;
				if (left->next != NULL)
					left->next->prev = left;
				if (right->prev == NULL)
					*list = right;

				/* Print the list after the swap*/
				print_list(*list);

				swapped = 1;
				tmp = left;
				left = right;
				right = tmp;
			}

			 left = left->next;
			 right = right->next;
		}

		/* Move from right to left */
		right = left->prev;

		while (right != NULL)
		{
			if (left->n < right->n)
			{
				/* Swap the nodes */
				 if (left->prev != NULL)
					 left->prev->next = right;
				 right->prev = left->prev;
				 left->prev = right;
				 left->next = right->next;
				 right->next = left;
				 if (left->next != NULL)
					 left->next->prev = left;

				 if (right->prev == NULL)
					 *list = right;

				 /* Print the list after the swap */
				 print_list(*list);


				 swapped = 1;
				 tmp = left;
				 left = right;
				 right = tmp;
			}
			left = left->prev;
			right = right->prev;
		}

		/* Reset the pointers for the next iteration */
		left = (*list);
		right = left->next;
	}
}
