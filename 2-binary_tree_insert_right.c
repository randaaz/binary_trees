#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the parent node to insert the right-child in
 * @value: value to store in the new node
 *
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *w_nd;

	if (parent == NULL)
	{
		return (NULL);
	}

	w_nd = malloc(sizeof(binary_tree_t));

	if (w_nd == NULL)
	{
		return (NULL);
	}
	w_nd->n = value;
	w_nd->parent = parent;
	w_nd->left = NULL;
	w_nd->right = NULL;

	if (parent->right != NULL)
	{
		w_nd->right = parent->right;
		parent->right->parent = w_nd;

	}
	parent->right = w_nd;
	return (w_nd);
}
