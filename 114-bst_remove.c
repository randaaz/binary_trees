#include "binary_trees.h"
/**
 * caliph - Finds the leftmost node in a binary tree
 * @node: Pointer to the root of the tree
 *
 * Return: Value of the leftmost node
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
 * t_ch - Updates the value of a node with the value of its in-order successor
 * @root: Pointer to the root of the tree
 *
 * Return: New value of the node
 */
int t_ch(bst_t *root)
{
	int n_v = 0;

	n_v = caliph(root->right);
	root->n = n_v;
	return (n_v);
}
/**
 * rm_ty - Removes a node with a given value from a BST
 * @root: Pointer to the root of the tree
 *
 * Return: 0
 */
int  rm_ty(bst_t *root)
{
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
		return (t_ch(root));
}
/**
 * bst_remove - Removes a node with a given value from a BST
 * @root: Pointer to the root of the tree
 * @value: Value to remove from the tree
 *
 * Return: Pointer to the new root of the tree
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
