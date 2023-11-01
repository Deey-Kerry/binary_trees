#include "binary_trees.h"
/**
 * array_to_bst - function that builds a Binary Search Tree from
 * an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return:  root node of the created BST, or NULL
 */
bst_t *array_to_bst(int *array, size_t size)
{
	unsigned int a = 0;
	bst_t *root = NULL;

	for (; a < size; a++)
	{
		bst_insert(&root, array[a]);
	}

	return (root);
}
