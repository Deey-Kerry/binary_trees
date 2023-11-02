#include "binary_trees.h"
/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: double pointer to the root node of the Heap to insert
 * the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *newNode, *flip;
	int size, leaves, sub, bit, level, temp;

	if (root == NULL)
		return (NULL);
	if ((*root) == NULL)
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	leaves = size;
	level = 0;
	sub = 1;
	for (; leaves >= sub; sub *= 2, level++)
		leaves -= sub;
	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
	{
		if (leaves & bit)
		{
			tree = tree->right;
		}
		else
		{
			tree = tree->left;
		}
	}
	newNode = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = newNode) : (tree->left = newNode);
	flip = newNode;
	for (; flip->parent && (flip->n > flip->parent->n); flip = flip->parent)
	{
		temp = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = temp;
		newNode = newNode->parent;
	}
	return (newNode);
}

/**
 * binary_tree_size - size of binary tree
 * @tree: pointer to tree node
 * Return: size of tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
