#include "binary_trees.h"
/**
 * b_t_h - function to calculate the height of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t s = 0;
	size_t m = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			s = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			m = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((s > m) ? s : m);
	}
}
/**
 * binary_tree_depth - function to calculate the depth
 * @tree: pointer to the node
 *
 * Return: depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
/**
 * l_nd - function to create a new node for the linked list
 * @head: pointer to the head of the linked list
 * @tree: pointer to the node
 * @level: level of the node
 */
void l_nd(link_t **head, const binary_tree_t *tree, size_t level)
{
	link_t *w, *a;

	w = malloc(sizeof(link_t));
	if (w == NULL)
	{
		return;
	}
	w->n = level;
	w->node = tree;
	if (*head == NULL)
	{
		w->next = NULL;
		*head = w;
	}
	else
	{
		a = *head;
		while (a->next != NULL)
		{
			a = a->next;
		}
		w->next = NULL;
		a->next = w;
	}
}
/**
 * rec - function to recursively traverse the tree and create the linked list
 * @head: pointer to the head of the linked list
 * @tree: pointer to the root node of the tree
 */
void rec(link_t **head, const binary_tree_t *tree)
{
	size_t level = 0;

	if (tree != NULL)
	{
		level = binary_tree_depth(tree);
		l_nd(head, tree, level);
		rec(head, tree->left);
		rec(head, tree->right);
	}
}
/**
 * binary_tree_levelorder - function to traverse the binary tree in level-order
 * @tree: pointer to the root node of the tree
 * @func: pointer to the function to be called for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_t *head, *a;
	size_t he = 0, co = 0;

	if (!tree || !func)
	{
		return;
	}
	else
	{
		he = binary_tree_height(tree);
		head = NULL;
		rec(&head, tree);
		while (co <= he)
		{
			a = head;
			while (a != NULL)
			{
				if (co == a->n)
				{
					func(a->node->n);
				}
				a = a->next;
			}
			co++;
		}
		while (head != NULL)
		{
			a = head;
			head = head->next;
			free(a);
		}
	}
}
