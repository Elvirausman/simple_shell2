#include "main.h"

/**
 * add_node_start - adds a node to the start of the list
 * @h: address of pointer to head node
 * @str: str field of node
 * @n: node index used by history
 *
 * Return: size of list
 */
list_t *add_node_start(list_t **h, const char *str, int n)
{
	list_t *new_head;

	if (!h)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->n = n;
	if (str)
	{
		new_head->str = _strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *h;
	*h = new_head;
	return (new_head);
}

/**
 * add_node_end - adds a node to the end of the list
 * @h: address of pointer to head node
 * @str: str field of node
 * @n: node index used by history
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **h, const char *str, int n)
{
	list_t *new_node, *node;

	if (!h)
		return (NULL);

	node = *h;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->n = n;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*h = new_node;
	return (new_node);
}

/**
 * print_list - prints only the str element of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * rm_node - deletes node at given index
 * @h: address of pointer to first node
 * @ind: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int rm_node(list_t **h, unsigned int ind)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!h || !*h)
		return (0);

	if (!ind)
	{
		node = *h;
		*h = (*h)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *h;
	while (node)
	{
		if (i == ind)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_up_list - frees all nodes of a list
 * @h_ptr: address of pointer to head node
 *
 * Return: void
 */
void free_up_list(list_t **h_ptr)
{
	list_t *node, *next_node, *h;

	if (!h_ptr || !*h_ptr)
		return;
	h = *h_ptr;
	node = h;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*h_ptr = NULL;
}
