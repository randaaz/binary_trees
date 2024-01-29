#include "binary_trees.h"
/**
 * a_st - Recursively builds an AVL tree from a sorted array
 * @parent: Pointer to the parent node
 * @array: Pointer to the sorted array of integers
 * @begin: Index of the beginning of the array segment
 * @last: Index of the last element of the array segment
 *
 * Return: Pointer to the root of the created AVL tree, or NULL on failure
 */
avl_t *a_st(avl_t *parent, int *array, int begin, int last)
{
	avl_t *rt;
	binary_tree_t *a;
	int md = 0;

	if (begin <= last)
	{
		md = (begin + last) / 2;
		a = binary_tree_node((binary_tree_t *)parent, array[md]);
		if (a == NULL)
			return (NULL);
		rt = (avl_t *)a;
		rt->left = a_st(rt, array, begin, md - 1);
		rt->right = a_st(rt, array, md + 1, last);
		return (rt);
	}
	return (NULL);
}
/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the sorted array of integers
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (a_st(NULL, array, 0, ((int)(size)) - 1));
}
