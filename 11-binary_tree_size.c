#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: Size of the tree or 0 if tree is NULL.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t sz = 0, m = 0, s = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		s = binary_tree_size(tree->left);
		m = binary_tree_size(tree->right);
		sz = m + s + 1;
	}
	return (sz);
}
