#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the
 * lowest common ancestor of two nodes in a binary tree.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: Pointer to the lowest common ancestor, or NULL if no ancestor found.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *pt, *u;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	pt = first->parent;
	u = second->parent;
	if (pt == NULL || first == u || (!pt->parent && u))
	{
		return (binary_trees_ancestor(first, u));
	}
	else if (u == NULL || pt == second || (!u->parent && pt))
	{
		return (binary_trees_ancestor(pt, second));
	}
	return (binary_trees_ancestor(pt, u));
}
