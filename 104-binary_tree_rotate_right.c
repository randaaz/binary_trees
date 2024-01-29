#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right rotation on a binary tree.
 * @tree: Pointer to the root of the binary tree.
 * Return: Pointer to the new root after the rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *p;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}
	p = tree->left;
	tree->left = p->right;
	if (p->right != NULL)
	{
		p->right->parent = tree;
	}
	p->right = tree;
	p->parent = tree->parent;
	tree->parent = p;
	return (p);
}
