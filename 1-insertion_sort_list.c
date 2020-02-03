#include "sort.h"

/**
 * insertion_sort_list - a function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: the list to sort
 *
 * Return: None
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *current;
	int elem;

	if (list == NULL || *list == NULL)
		return;

	for (temp = (*list)->next; temp != NULL; temp = temp->next)
	{
		elem = temp->n;
		for (current = temp->prev; current != NULL; current = current->prev)
		{
			if (elem < current->n)
			{
				swap_nodes(current, temp);

				if (current->prev == NULL)
					*list = current;
				else if (temp->prev == NULL)
					*list = temp;
				print_list(*list);

				continue;
			}
		}
	}
}
/**
 * swap_nodes - function that swaps the nodes of a doubly linked list
 * @nodeL: the left node
 * @nodeR: the right node
 *
 * Return: None
 */
void swap_nodes(listint_t *nodeL, listint_t *nodeR)
{
	nodeL->next = nodeR->next;
	nodeR->next = nodeL;
	nodeR->prev = nodeL->prev;
	nodeL->prev = nodeR;

	if (nodeR->prev != NULL)
		nodeR->prev->next = nodeR;
	if (nodeL->next != NULL)
		nodeL->next->prev = nodeL;
}
