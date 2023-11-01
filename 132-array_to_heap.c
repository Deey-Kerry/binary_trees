#include "binary_trees.h"
/**
 * array_to_heap - builds a Max Binary Heap tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: NULL or pointer to root node
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int a = 0;
	heap_t *root;

	root = NULL;
	for (; a < size; a++)
		heap_insert(&root, array[a]);

	return (root);
}
