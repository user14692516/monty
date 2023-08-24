#include "monty.h"
#include "lists.h"
/**
 * insert_dnodeint_at_index - inserting a node at a given index
 * @h: double list pointer
 * @idx: index of the node that is supposed to be inserted.
 * @n: insertible data.
 * Return: address of the new node
 * NULL if it fails
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int j;
	dlistint_t *new;
	dlistint_t *temp = *h;

	if (idx == 0)
		return (add_dnodeint(h, n));

	for (j = 0; temp && j < idx; j++)
	{
		if (j == idx - 1)
		{
			if (temp->next == NULL)
				return (add_dnodeint_end(h, n));
			new = malloc(sizeof(dlistint_t));
			if (!new || !h)
				return (NULL);
			new->n = n;
			new->next = NULL;
			new->next = temp->next;
			new->prev = temp;
			temp->next->prev = new;
			temp->next = new;
			return (new);
		}
		else
			temp = temp->next;
	}

	return (NULL);
}
/**
 * add_dnodeint_end - adding a new node at the end of a doubly linked list
 * @head: double list pointer.
 * @n: data to inserted to the new node.
 * Return: the address of the new element
 * NULL if it fails
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *temp = *head;

	if (!head)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = new;
	new->prev = temp;

	return (new);
}
/**
 * free_dlistint -freeing a doubly linked list
 * @head: pointer to the list that is supposed to be freed
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
