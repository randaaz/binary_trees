#include "binary_trees.h"

/**
 * b_t_h - Calculate the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree
 */

size_t b_t_h(const binary_tree_t *tree)
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
			s = tree->left ? 1 + b_t_h(tree->left) : 1;
			m = tree->right ? 1 + b_t_h(tree->right) : 1;
		}
		return ((s > m) ? s : m);
		}
}

/**
 * b_v - Check if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree
 * @lower: Lower bound value
 * @high: Upper bound value
 *
 * Return: 1 if valid AVL tree, 0 otherwise
 */
int b_v(const binary_tree_t *tree, int lower, int high)
{
	size_t h_l, h_r, bal;

	if (tree != NULL)
	{
		if (tree->n > high || tree->n < lower)
		{
			return (0);
		}
		h_l = b_t_h(tree->left);
		h_r = b_t_h(tree->right);
		bal = h_l > h_r ? h_l - h_r : h_r - h_l;
		if (bal > 1)
		{
			return (0);
		}
		return (b_v(tree->left, lower, tree->n - 1) &&
			b_v(tree->right, tree->n + 1, high));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Check if a binary tree is an AVL tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (b_v(tree, INT_MIN, INT_MAX));
}
