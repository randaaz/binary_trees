#include "binary_trees.h"
/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the parent node to insert the right-child in
 * @value: value to store in the new node
 *
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
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
	if (parent->right != NULL)
	{
		n_nd->right = parent->right;
		parent->right->parent = n_nd;
	}
	parent->right = n_nd;
	return (n_nd);
}
