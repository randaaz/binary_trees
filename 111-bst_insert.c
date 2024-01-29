#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a Binary Search Tree (BST).
 * @tree: Pointer to a pointer to the root of the BST.
 * @value: Value to insert into the BST.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *w, *t;
	binary_tree_t *a;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		a = binary_tree_node((binary_tree_t *)(*tree), value);
		w = (bst_t *)a;
		*tree = w;
	}
	else
	{
		t = *tree;
		if (value < t->n)
		{
			if (t->left)
				w = bst_insert(&t->left, value);
			else
			{
				a = binary_tree_node((binary_tree_t *)t, value);
				w = t->left = (bst_t *)a;
			}
		}
		else if (value > t->n)
		{
			if (t->right)
				w = bst_insert(&t->right, value);
			else
			{
				a = binary_tree_node((binary_tree_t *)t, value);
				w = t->right = a;
			}
		}
		else
			return (NULL);
	}
	return (w);
}
