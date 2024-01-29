#include "binary_trees.h"

/**
 * n_nd - Creates a new linked list node with a given binary tree node
 * @node: Pointer to a binary tree node
 * Return: Pointer to the new linked list node
 */

link_t *n_nd(binary_tree_t *node)
{
	link_t *w;

	w =  malloc(sizeof(link_t));
	if (w == NULL)
	{
		return (NULL);
	}
	w->node = node;
	w->next = NULL;

	return (w);
}

/**
 * free_u - Frees the linked list
 * @head: Pointer to the head of the linked list
 */

void free_u(link_t *head)
{
	link_t *t_nd;

	while (head)
	{
		t_nd = head->next;
		free(head);
		head = t_nd;
	}
}

/**
 * _push_me - Pushes a new node onto the linked list
 * @nd: Binary tree node to be pushed
 * @head: Head of the linked list
 * @t: Pointer to the tail of the linked list
 */

void _push_me(binary_tree_t *nd, link_t *head, link_t **t)
{
	link_t *w;

	w = n_nd(nd);
	if (w == NULL)
	{
		free_u(head);
		exit(1);
	}
	(*t)->next = w;
	*t = w;
}

/**
 * _pop_me - Pops a node from the linked list
 * @head: Pointer to the head of the linked list
 */

void _pop_me(link_t **head)
{
	link_t *t_nd;

	t_nd = (*head)->next;
	free(*head);
	*head = t_nd;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root of the binary tree
 * Return: 1 if complete, 0 otherwise
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	link_t *h, *t;
	int flag = 0;

	if (tree == NULL)
	{
		return (0);
	}
	h = t = n_nd((binary_tree_t *)tree);
	if (h == NULL)
	{
		exit(1);
	}
	while (h != NULL)
	{
		if (h->node->left != NULL)
		{
			if (flag == 1)
			{
				free_u(h);
				return (0);
			}
			_push_me(h->node->left, h, &t);
		}
		else
			flag = 1;
		if (h->node->right != NULL)
		{
			if (flag == 1)
			{
				free_u(h);
				return (0);
			}
			_push_me(h->node->right, h, &t);
		}
		else
			flag = 1;
		_pop_me(&h);
	}
	return (1);
}
