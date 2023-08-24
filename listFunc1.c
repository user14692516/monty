#include "monty.h"

/**
 * dlistint_len - returning node numbers in a doubly linked list
 * @h: list pointer
 * Return: node numbers
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t nodes = 0;

	if (!h)
		return (0);

	while (h)
	{
		nodes++;
		h = h->next;
	}

	return (nodes);
}

/**
 * add_dnodeint - adding a new node in a doubly linked list
 * @head: double pointer for the list.
 * @n: data that is inserted in a new node.
 * Return: address ot new element
 * NULL if it fails
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	if (!head)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);

	new->n = n;

	new->next = *head;
	new->prev = NULL;

	if (*head)
		(*head)->prev = new;

	*head = new;

	return (new);
}

/**
 * print_dlistint -printing doubly linked list
 * @h: list pointer.
 * Return: node numbers in a list
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t nodes = 0;

	if (!h)
		return (0);

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		nodes++;
	}

	return (nodes);
}

/**
 * delete_dnodeint_at_index - deleteing a node in a doubly list
 * @head: double pointer to the list
 * @index: index a need that is supposed to be deleted
 * Return: 1 on success
 * -1 on failure
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp = *head;
	unsigned int j = 0;

	if (!index)
	{
		(*head) = temp->next;
		if (temp->next)
			temp->next->prev = NULL;
		temp->next = NULL;
		free(temp);
		return (1);
	}

	while (j < index)
	{
		temp = temp->next;
		j++;
		if (!temp)
			return (0);
	}

	temp->prev->next = temp->next;
	if (temp->next)
		temp->next->prev = temp->prev;
	free(temp);

	return (1);
}
/**
 * get_dnodeint_at_index - getting the nth node of a doubly linked list
 * @head: list pointer.
 * @index: index of a node that is supposed to be returned
 * Return: address of the node
 * NULL if it fails.
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int j = 0;

	if (!head)
		return (NULL);

	while (head && j < index)
	{
		head = head->next;
		j++;
	}

	return (head ? head : NULL);
}
