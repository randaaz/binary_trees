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

	size_t  nd = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		nd += ((tree->left || tree->right) ? 1 : 0);
		nd += binary_tree_nodes(tree->left);
		nd += binary_tree_nodes(tree->right);
		return (nd);
	}
}
