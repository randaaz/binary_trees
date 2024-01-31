#include "binary_trees.h"

/**
 * _in_nd - Inserts a node into an AVL tree.
 * @tree: Pointer to the root of the AVL tree.
 * @parent: Pointer to the parent of the current node.
 * @w: Pointer to the newly inserted node.
 * @nv: Value to insert into the AVL tree
 *
 * Return: Pointer to the newly inserted node or NULL on failure.
 */

avl_t *_in_nd(avl_t **tree, avl_t *parent, avl_t **w, int nv)
{
	int bv;

	if (*tree == NULL)
		return (*w = binary_tree_node(parent, nv));
	if ((*tree)->n > nv)
	{
		(*tree)->left = _in_nd(&(*tree)->left, *tree, w, nv);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < nv)
	{
		(*tree)->right = _in_nd(&(*tree)->right, *tree, w, nv);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
	{
		return (*tree);
	}
	bv = binary_tree_balance(*tree);
	if (bv > 1 && (*tree)->left->n > nv)
	{
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bv > 1 && (*tree)->left->n < nv)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bv < -1 && (*tree)->right->n < nv)
	{
		*tree = binary_tree_rotate_left(*tree);
	}
	else if (bv < -1 && (*tree)->right->n > nv)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: Pointer to the root of the AVL tree.
 * @value: Value to insert into the AVL tree.
 *
 * Return: Pointer to the newly inserted node or NULL on failure.
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *w = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	_in_nd(tree, *tree, &w, value);
	return (w);
}
