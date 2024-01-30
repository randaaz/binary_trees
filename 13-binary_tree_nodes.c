#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at
 * least one child in a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: Number of nodes with at least one child, or 0 if tree is NULL.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t l = 0;
	size_t r = 0;


	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left == NULL && tree->right == NULL)
	{
		return (0);
	}
	l = binary_tree_nodes(tree->left);
	r = binary_tree_nodes(tree->right);
	return (1 + l + r);
}
