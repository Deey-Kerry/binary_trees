#include "binary_trees.h"
/**
 * sorted_array_to_avl - a function that builds an AVL tree from
 * an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: a pointer to the root node of the created AVL tree,
 * or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t mid;

	if (array == NULL)
		return (NULL);
	mid = (size - 1) / 2;
	tree = binary_tree_node(NULL, array[mid]);

	sata_helper(&tree, array, -1, mid);
	sata_helper(&tree, array, mid, size);
	return (tree);
}

/**
 * sata_helper - helps check the sata in array
 * @root: pointer to the root node of the tree where you will
 * remove a node
 * @array: pointer to the first element of the array to be converted
 * @lo: lower index
 * @hi: higher index
 */
void sata_helper(avl_t **root, int *array, size_t lo, size_t hi)
{
	avl_t *newNode;
	size_t mid;

	newNode = NULL;

	if (hi - lo > 1)
	{
		mid = (hi - lo) / 2 + lo;
		newNode = binary_tree_node(*root, array[mid]);
		if (array[mid] > (*root)->n)
			(*root)->right = newNode;
		else if (array[mid] < (*root)->n)
			(*root)->left = newNode;

		sata_helper(&newNode, array, lo, mid);
		sata_helper(&newNode, array, mid, hi);
	}
}
