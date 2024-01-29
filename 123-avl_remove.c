#include "binary_trees.h"

/**
 * _bal_me - Balances an AVL tree after node removal.
 * @tree: Pointer to the root of the AVL tree.
 */

void _bal_me(avl_t **tree)
{
	int bv;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	_bal_me(&(*tree)->left);
	_bal_me(&(*tree)->right);
	bv = binary_tree_balance((const binary_tree_t *)*tree);
	if (bv > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bv < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * caliph - Calculates the leftmost value of a BST.
 * @node: Pointer to the root of a BST.
 *
 * Return: Leftmost value.
 */

int caliph(bst_t *node)
{
	int l = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		l = caliph(node->left);
		if (l == 0)
		{
			return (node->n);
		}
		return (l);
	}

}

/**
 * rm_ty - Removes a node from a BST.
 * @root: Pointer to the node to be removed.
 *
 * Return: Leftmost value of the right subtree.
 */

int rm_ty(bst_t *root)
{
	int n_v = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		n_v = caliph(root->right);
		root->n = n_v;
		return (n_v);
	}
}

/**
 * bst_remove - Removes a node from a BST.
 * @root: Pointer to the root of the BST.
 * @value: Value to be removed.
 *
 * Return: Pointer to the root of the modified BST.
 */

bst_t *bst_remove(bst_t *root, int value)
{
	int ty = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		ty = rm_ty(root);
		if (ty != 0)
			bst_remove(root->right, ty);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: Pointer to the root of the AVL tree.
 * @value: Value to be removed.
 *
 * Return: Pointer to the root of the modified AVL tree.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_b = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_b == NULL)
		return (NULL);
	_bal_me(&root_b);
	return (root_b);
}
