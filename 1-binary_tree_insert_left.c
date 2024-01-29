#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a new node as the left child of a parent
 * @parent: Pointer to the parent node.
 * @value: Value to be stored in the new node.
 *
 * Return: Pointer to the newly created node, or NULL on failure.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *n_nd;

	if (parent == NULL)
	{
		return (NULL);
	}

	n_nd = binary_tree_node(parent, value);
	if (n_nd == NULL)
	{
		return (NULL);
	}
	if (parent->left != NULL)
	{
		n_nd->left = parent->left;
		parent->left->parent = n_nd;
	}
	parent->left = n_nd;
	return (n_nd);
}
