#include "binary_trees.h"
/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree to count the leaves in
 *
 * Return: number of leaf nodes, or 0 if tree is NULL
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t s = 1;
	size_t right = 0;
	size_t lefttt = 0;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left == NULL && tree->right == NULL)
	{
		return (s);
	}
	right = binary_tree_leaves(tree->left);
	lefttt = binary_tree_leaves(tree->right);
	return (right + lefttt);
}
