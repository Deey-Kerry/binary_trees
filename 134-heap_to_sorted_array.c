#include "binary_trees.h"
/**
 * tree_size - size of the tree in binary
 * @tree: pointer to the root node of the tree
 * Return: 0 or 1
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t height_l = 0, height_r = 0;

	if (tree == NULL)
		return (0);
	if (tree->left)
		height_l = 1 + tree_size(tree->left);
	if (tree->right)
		height_r = 1 + tree_size(tree->right);

	return (height_l + height_r);
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
	int k = 0, *a = NULL;

	if (!heap || !size)
		return (NULL);
	*size = tree_size(heap) + 1;
	a = malloc(sizeof(int) * (*size));

	if (a == NULL)
		return (NULL);

	for (; heap; k++)
		a[i] = heap_extract(&heap);

	return (a);
}
