#include "binary_trees.h"
/**
 * c_s_t_L - Checks if the left subtree of a node satisfies BST property
 * @nd: Pointer to the node to check
 * @mx: Maximum value allowed in the subtree
 *
 * Return: 1 if the subtree satisfies the BST property, 0 otherwise
 */
int c_s_t_L(const binary_tree_t *nd, int mx)
{
	int l = 0, r = 0;

	if (nd == NULL)
	{
		return (1);
	}
	else
	{
		if (nd->n >= mx)
			return (0);
		l = c_s_t_L(nd->left, mx);
		r = c_s_t_L(nd->right, mx);
		if (l == r && l == 1)
			return (1);
		return (0);
	}
}
/**
 * c_s_t_R - Checks if the right subtree of a node satisfies BST property
 * @nd: Pointer to the node to check
 * @mn: Minimum value allowed in the subtree
 *
 * Return: 1 if the subtree satisfies the BST property, 0 otherwise
 */
int c_s_t_R(const binary_tree_t *nd, int mn)
{
	int l = 0, r = 0;

	if (nd == NULL)
	{
		return (1);
	}
	else
	{
		if (nd->n <= mn)
			return (0);
		l = c_s_t_R(nd->left, mn);
		r = c_s_t_R(nd->right, mn);
		if (l == r && l == 1)
			return (1);
		return (0);
	}
}
/**
 * binary_tree_is_bst - Checks if a binary tree is a BST
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int v = 0, left = 2, right = 2;

	if (tree == NULL)
		return (0);
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n < tree->n)
		return (0);
	if (tree->left && tree->left->n < tree->n)
	{
		v = c_s_t_L(tree->left, tree->n);
		if (v == 0)
			return (0);
		left = binary_tree_is_bst(tree->left);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		v = c_s_t_R(tree->right, tree->n);
		if (v == 0)
			return (0);
		right = binary_tree_is_bst(tree->right);
	}
	if (left != 2 || right != 2)
	{
		if (left == 0 || right == 0)
			return (0);
	}
	return (1);
}
