#include "binary_trees.h"
/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree to count the leaves in
 *
 * Return: number of leaf nodes, or 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t l = 0, s = 0, m = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		s = binary_tree_leaves(tree->left);
		m = binary_tree_leaves(tree->right);
		l = s + m;
		return ((!s && !m) ? l + 1 : l + 0);
	}
}
