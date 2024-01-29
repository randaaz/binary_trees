#include "binary_trees.h"

/**
 * maximum - Finds the maximum value in a heap.
 * @tree: Pointer to the root of the heap.
 *
 * Return: Pointer to the node containing the maximum value.
 */

heap_t *maximum(heap_t *tree)
{
	heap_t *curr_maximum, *l_maximum, *r_maximum;

	if (!tree->left)
		return (tree);
	l_maximum = maximum(tree->left);
	if (l_maximum->n > tree->n)
		curr_maximum = l_maximum;
	else
		curr_maximum = tree;
	if (tree->right)
	{
		r_maximum = maximum(tree->right);
		if (r_maximum->n > curr_maximum->n)
			curr_maximum = r_maximum;
		else
			curr_maximum = tree;
	}
	return (curr_maximum);
}

/**
 * rec_ex - Recursive function to extract the maximum value from a heap.
 * @tree: Pointer to the root of the heap.
 */

void rec_ex(heap_t *tree)
{
	heap_t *s_maximum, *r_maximum = NULL;

	if (!tree->left)
		return;
	s_maximum = maximum((tree)->left);
	if (tree->right)
		r_maximum = maximum(tree->right);
	if (r_maximum && r_maximum->n > s_maximum->n)
		s_maximum = r_maximum;
	tree->n = s_maximum->n;
	if (!s_maximum->left)
	{
		if (s_maximum->parent && s_maximum->parent->left == s_maximum)
			s_maximum->parent->left = NULL;
		if (s_maximum->parent && s_maximum->parent->right == s_maximum)
			s_maximum->parent->right = NULL;
		free(s_maximum);
	}
	else
		rec_ex(s_maximum);
}

/**
 * heap_extract - Extracts the maximum value from a heap.
 * @root: Pointer to the root of the heap.
 *
 * Return: The extracted value.
 */

int heap_extract(heap_t **root)
{
	int v;

	if (!*root)
		return (0);
	v = (*root)->n;
	if (!(*root)->left)
	{
		v = (*root)->n;
		free(*root);
		*root = NULL;
		return (v);
	}
	rec_ex(*root);
	return (v);
}
