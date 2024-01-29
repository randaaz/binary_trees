#include "binary_trees.h"

/**
 * b_t_h_b - function to compute the height of a binary tree
 * @tree: pointer to the root node of the tree to compute the height
 *
 * Return: height of the binary tree
 */

size_t b_t_h_b(const binary_tree_t *tree)
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
			s = tree->left ? 1 + b_t_h_b(tree->left) : 1;
			m = tree->right ? 1 + b_t_h_b(tree->right) : 1;
		}
		return ((s > m) ? s : m);
	}
}

/**
 * binary_tree_balance - function to compute the balanc
 * @tree: pointer to the root node of the tree
 *
 * Return: balance factor of the binary tree
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int r = 0, l = 0, t = 0;

	if (tree)
	{
		l = ((int)b_t_h_b(tree->left));
		r = ((int)b_t_h_b(tree->right));
		t = l - r;
	}
	return (t);
}
