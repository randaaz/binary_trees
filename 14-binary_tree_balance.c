#include "binary_trees.h"

/**
 * binary_tree_height_me - function to compute the height of a binary tree
 * @tree: pointer to the root node of the tree to compute the height
 *
 * Return: height of the binary tree
 */

size_t binary_tree_height_me(const binary_tree_t *tree)
{
	size_t l = 0;
	size_t r = 0;


	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left == NULL && tree->right == NULL)
	{
		return (1);
	}
	l = binary_tree_height_me(tree->left);
	r = binary_tree_height_me(tree->right);
	if (l > r)
	{
		return (l + 1);
	}
	else
	{
		return (r + 1);
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
	int lft = 0;
	int rigt = 0;

	if (tree)
	{
		lft = (int)binary_tree_height_me(tree->left);
		rigt = (int)binary_tree_height_me(tree->right);
	}
	return (lft - rigt);
}
