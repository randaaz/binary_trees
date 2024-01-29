#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the size.
 * Return: The size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * t_is_co - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 * @i: Index of the current node.
 * @cnodes: The number of nodes in the tree.
 * Return: 1 if complete, 0 otherwise.
 */
int t_is_co(const binary_tree_t *tree, int i, int cnodes)
{
	if (tree == NULL)
		return (1);

	if (i >= cnodes)
		return (0);

	return (t_is_co(tree->left, (2 * i) + 1, cnodes) &&
		t_is_co(tree->right, (2 * i) + 2, cnodes));
}


/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t cnodes;

	if (tree == NULL)
		return (0);

	cnodes = binary_tree_size(tree);

	return (t_is_co(tree, 0, cnodes));
}

/**
 * c_p - Checks if a node violates max heap property.
 * @tree: A pointer to the node to check.
 * Return: 1 if node doesn't violate max heap property, 0 otherwise.
 */
int c_p(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->n > tree->parent->n)
		return (0);

	return (c_p(tree->left) && c_p(tree->right));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a max heap.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if a max heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!binary_tree_is_complete(tree))
		return (0);

	return (c_p(tree->left) && c_p(tree->right));
}
