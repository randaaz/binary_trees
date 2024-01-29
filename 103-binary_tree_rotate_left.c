#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left rotation on a binary tree node
 * @tree: A pointer to the root node of the tree to rotate
 *
 * Return: A pointer to the new root node of the rotated tree
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *piv;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}
	piv = tree->right;
	tree->right = piv->left;
	if (piv->left != NULL)
	{
		piv->left->parent = tree;
	}
	piv->left = tree;
	piv->parent = tree->parent;
	tree->parent = piv;
	return (piv);
}
