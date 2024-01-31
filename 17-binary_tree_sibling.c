#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node in a binary tree.
 * @node: Pointer to the node for which to find the sibling.
 *
 * Return: Pointer to the sibling node,
 * or NULL if no sibling or if node is NULL.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *p;

	if (node == NULL || node->parent == NULL)
	{
		return (NULL);
	}
	if (node->parent->left == NULL || node->parent->right == NULL)
	{
		return (NULL);
	}
	if (node->parent->right != node)
	{
		if (node->parent->left == NULL || node->parent->right != NULL)
		{
			p = node->parent->right;
			return (p);

		}
	}
	if (node->parent->left != node)
	{
		if (node->parent->left != NULL || node->parent->right == NULL)
		{
			p = node->parent->left;
			return (p);

		}
	}
	binary_tree_sibling(node->parent->left);
	binary_tree_sibling(node->parent->right);
}
