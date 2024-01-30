#include "binary_trees.h"

/**
 * _he - Calculates the height of a binary tree.
 * @tree: Pointer to the root of the binary tree.
 *
 * Return: Height of the binary tree, or -1 if the tree is NULL
 */

int _he(const binary_tree_t *tree)
{
	int l = 0;
	int r = 0;

	if (tree == NULL)
		return (-1);

	l = _he(tree->left);
	r = _he(tree->right);

	if (l > r)
		return (l + 1);

	return (r + 1);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root of the binary tree.
 *
 * Return: 1 if the binary tree is perfect, 0 otherwise.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree && _he(tree->left) == _he(tree->right))
	{
		if (_he(tree->left) == -1)
			return (1);

		if ((tree->left && !((tree->left)->left) && !((tree->left)->right))
				&& (tree->right && !((tree->right)->left) && !((tree->right)->right)))
			return (1);

		if (tree && tree->left && tree->right)
			return (binary_tree_is_perfect(tree->left) &&
					binary_tree_is_perfect(tree->right));
	}

	return (0);
}

/**
 * _swap_me - Swaps a node with its child in a max heap.
 * @arg_node: Pointer to the address of the parent node.
 * @arg_child: Pointer to the address of the child node.
 */

void _swap_me(heap_t **arg_node, heap_t **arg_child)
{
	heap_t *nd, *chd, *nd_chd, *nd_l, *nd_r, *parent;
	int left_right;

	nd = *arg_node, chd = *arg_child;
	if (chd->n > nd->n)
	{
		if (chd->left)
			chd->left->parent = nd;
		if (chd->right)
			chd->right->parent = nd;
		if (nd->left == chd)
			nd_chd = nd->right, left_right = 0;
		else
			nd_chd = nd->left, left_right = 1;
		nd_l = chd->left, nd_r = chd->right;
		if (left_right == 0)
		{
			chd->right = nd_chd;
			if (nd_chd)
				nd_chd->parent = chd;
			chd->left = nd;
		}
		else
		{
			chd->left = nd_chd;
			if (nd_chd)
				nd_chd->parent = chd;
			chd->right = nd;
		}
		if (nd->parent)
		{
			if (nd->parent->left == nd)
				nd->parent->left = chd;
			else
				nd->parent->right = chd;
		}
		parent = nd->parent, chd->parent = parent;
		nd->parent = chd, nd->left = nd_l;
		nd->right = nd_r, *arg_node = chd;
	}
}

/**
 * heap_insert - Inserts a value into a max heap.
 * @root: Pointer to the root of the max heap.
 * @value: Value to be inserted.
 *
 * Return: Pointer to the newly inserted node.
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *w_nd;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	if (binary_tree_is_perfect(*root) || !binary_tree_is_perfect((*root)->left))
	{
		if ((*root)->left)
		{
			w_nd = heap_insert(&((*root)->left), value);
			_swap_me(root, &((*root)->left));
			return (w_nd);
		}
		else
		{
			w_nd = (*root)->left = binary_tree_node(*root, value);
			_swap_me(root, &((*root)->left));
			return (w_nd);
		}
	}

	if ((*root)->right)
	{
		w_nd = heap_insert(&((*root)->right), value);
		_swap_me(root, (&(*root)->right));
		return (w_nd);
	}
	else
	{
		w_nd = (*root)->right = binary_tree_node(*root, value);
		_swap_me(root, &((*root)->right));
		return (w_nd);
	}

	return (NULL);
}
