#include "binary_trees.h"
/**
 * array_to_avl - a function that builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to the root node of the created AVL tree, or
 * NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	unsigned int a = 0;
	avl_t *root;

	root = NULL;

	for (; a < size; a++)
		avl_insert(&root, array[a]);

	return (root);
}
