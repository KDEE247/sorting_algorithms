#include "sort.h"
/**
 * swap_nodes - Swaps 2 nodes in a listint_t Doubly-linked List.
 * @h: A Ptr to the Head of Doubly-Linked Lists.
 * @n1: A Ptr to the 1st Node to Swap.
 * @n2: 2nd node to Swap.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts Doubly Linked Lists of Integers
 * via the Insertion Sort Algorithm.
 * @list: Ptr to the Head of a Doubly-Linked List of Integers.
 * Description: Prints the List after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
