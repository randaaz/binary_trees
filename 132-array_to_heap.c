#include "binary_trees.h"

/**
 * array_to_heap - Builds a binary heap from an array of integers.
 * @array: Pointer to the array of integers.
 * @size: Size of the array.
 *
 * Return: Pointer to the root node of the created heap, or NULL on failure.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *tree;
	size_t ii;

	tree = NULL;

	for (ii = 0; ii < size; ii++)
	{
		heap_insert(&tree, array[ii]);
	}

	return (tree);
}
