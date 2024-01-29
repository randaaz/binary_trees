#include "binary_trees.h"
/**
 * bst_search - Searches for a value in a Binary Search Tree (BST).
 * @tree: Pointer to the root of the BST.
 * @value: Value to search for in the BST.
 *
 * Return: Pointer to the node containing
 * the matching value, or NULL if not found.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *f;

	if (tree == NULL)
		return (NULL);

	if (value < tree->n)
	{
		f = bst_search(tree->left, value);
	}
	else if (value > tree->n)
	{
		f = bst_search(tree->right, value);
	}
	else if (value == tree->n)
		return ((bst_t *)tree);
	else
		return (NULL);
	return (f);
}
