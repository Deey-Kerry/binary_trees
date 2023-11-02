#include "binary_trees.h"
/**
 * tree_size - size of the tree in binary
 * @tree: pointer to the root node of the tree
 * Return: 0 or 1
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t height_left = 0, height_right = 0;

	if (tree == NULL)
		return (0);
	if (tree->left)
		height_left = 1 + tree_size(tree->left);
	if (tree->right)
		height_right = 1 + tree_size(tree->right);

	return (height_left + height_right);
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap to a sorted
 * array of integers
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 * Return: array sorted in descending order
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int k = 0, *b = NULL;

	if (!heap || !size)
		return (NULL);
	*size = tree_size(heap) + 1;
	b = malloc(sizeof(int) * (*size));

	if (b == NULL)
		return (NULL);

	for (; heap; k++)
		b[k] = heap_extract(&heap);

	return (b);
}
