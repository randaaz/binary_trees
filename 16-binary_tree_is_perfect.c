#include "binary_trees.h"
/**
 * t_is_p - recursive function to check if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int t_is_p(const binary_tree_t *tree)
{
	int s = 0, m = 0;

	if (tree->left && tree->right)
	{
		s = 1 + t_is_p(tree->left);
		m = 1 + t_is_p(tree->right);
		if (m == s && m != 0 && s != 0)
			return (m);
		return (0);
	}
	else if (!tree->left && !tree->right)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int re = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		re = t_is_p(tree);
		if (re != 0)
		{
			return (1);
		}
		return (0);
	}
}
