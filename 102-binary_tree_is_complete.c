#include "binary_trees.h"
/**
 * binary_tree_is_complete - a function that checks if a binary
 * tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: If tree is NULL, your function must return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t s;

	if (tree == NULL)
		return (0);
	s = binary_tree_size(tree);

	return (btic_helper(tree, 0, s));
}

/**
 * btic_helper - checks for tree completion
 * @tree: pointer to the root node of the tree to check
 * @index: first node
 * @size: size of tree
 * Return: 1 0r 0
 */
int btic_helper(const binary_tree_t *tree, size_t index, size_t size)
{
	if (tree == NULL)
		return (1);
	if (index >= size)
		return (0);
	return (btic_helper(tree->left, 2 * index + 1, size) &&
		btic_helper(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - checks size of tree
 * @tree: pointer to the root node of the tree to check
 * Return: 0 or 1
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}
