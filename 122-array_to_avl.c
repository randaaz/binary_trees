#include "binary_trees.h"

/**
 * array_to_avl - Build an AVL tree from an array of integers
 * @array: Pointer to the array of integers
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root of the created AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t ii, jj = 0;
	avl_t *rt;

	rt = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (ii = 0; ii < size; ii++)
	{
		for (jj = 0; jj < ii; jj++)
		{
			if (array[jj] == array[ii])
				break;
		}
		if (jj == ii)
		{
			if (avl_insert(&rt, array[ii]) == NULL)
			{
				return (NULL);
			}
		}
	}
	return (rt);
}
