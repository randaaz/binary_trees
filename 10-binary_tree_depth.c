#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 *
 * Return: depth of the node, or 0 if tree is NULL or node has no parent
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t sum;

	if (tree && tree->parent)
	{
		sum = sum + 1;
		binary_tree_depth(tree->parent);
	}
	else
	{
		return (0);
	}
	return (sum);
}
