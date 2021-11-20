#include "sort.h"

void move_to_pos(listint_t *node, listint_t ***list_head);

/**
 * insertion_sort_list - sorts an array using insertion
 * sort algorithm
 * @list: double pointer to the doubly linked list to
 * be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *point_in_exec, *temp;

	if (!list)
		return;

	point_in_exec = (*list)->next;

	while (point_in_exec)
	{
		temp = point_in_exec->next;

		if (point_in_exec->n < point_in_exec->prev->n)
		{
			move_to_pos(point_in_exec, &list);
		}

		point_in_exec = temp;
	}
}

/**
 * move_to_pos - moves a node to correct position by
 * comparing the value of n to that of the previous node
 * @node: node to move to correct position
 * @list_head: triple pointer to the head of the list
 */
void move_to_pos(listint_t *node, listint_t ***list_head)
{
	listint_t *prevNode = node->prev;

	while (node->prev && (node->n < prevNode->n))
	{
		if (prevNode->prev)
			prevNode->prev->next = node;
		else
			*(*list_head) = node;

		node->prev = prevNode->prev;
		prevNode->prev = node;
		prevNode->next = node->next;

		if (node->next)
			node->next->prev = prevNode;
		node->next = prevNode;

		prevNode = node->prev;
		print_list(*(*list_head));
	}
}
