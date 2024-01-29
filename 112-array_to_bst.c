#include "binary_trees.h"
/**
 * array_to_bst - Converts an array into a binary search tree (BST)
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t ii = 0;
	bst_t *rt;

	rt = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (; ii < size; ii++)
	{
		if (ii == 0)
		{
			bst_insert(&rt, array[ii]);
		}
		else
		{
			bst_insert(&rt, array[ii]);
		}
	}
	return (rt);
}
