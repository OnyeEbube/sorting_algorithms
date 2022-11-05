#include "sort.h"

/**
 * swap_nodes - swap two nodes in a listint_t doubly-linked list
 * @h: A pointer to the head of the doubly linked list
 * @n1: a pointer to the first node to swap
 * @n2: the second node to swap
 *
 * Return: no return
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
		*h =n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the insertion sort algorithm
 * @list: is a pointer to the head of the list
 *
 * Return: no return
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *new, *tmp, *tmp1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (new = (*list)->next; new != NULL; new = tmp)
	{
		tmp = new->next;
		tmp1 = new->prev;

		while (tmp1 != NULL && new->n < tmp1->n)
		{
			swap_nodes(list, &tmp1, new);
			print_list((const listint_t *)*list);
		}
	}
}
