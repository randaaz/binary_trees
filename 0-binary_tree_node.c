#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 *
 * Return: pointer to the new node, or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *n_nd;

	n_nd = malloc(sizeof(binary_tree_t));
	if (n_nd == NULL)
	{
		return (NULL);
	}
	n_nd->n = value;
	n_nd->parent = parent;
	n_nd->left = NULL;
	n_nd->right = NULL;
	return (n_nd);
}
