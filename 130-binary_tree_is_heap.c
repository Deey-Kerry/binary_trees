#include "binary_trees.h"
/**
 * binary_tree_is_heap - function that checks if a binary tree is a
 * valid Max Binary Heap
 * @tree: pointer to the root node of the tree to check
 * Return: 1 or 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (btih_helper(tree));
}

/**
 * btih_helper - checks if a binary tree is a * valid Max Binary Heap
 * @tree: pointer to the root node of the tree to check
 * Return: 1 or 0
 */
int btih_helper(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (!binary_tree_is_complete(tree))
		return (0);

	if (tree->left)
		if (tree->left->n > tree->n)
			return (0);

	if (tree->right)
		if (tree->right->n > tree->n)
			return (0);

	return (btih_helper(tree->left) &&
			btih_helper(tree->right));
}

/**
 * binary_tree_is_complete - check if a tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 0 or 1
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);
	size = binary_tree_size(tree);
	return (btic_helper(tree, 0, size));
}

/**
 * btic_helper - check if a tree is complete
 * @tree: pointer to the root node of the tree to check
 * @index: starting node
 * @size: number of nodes
 * Return: 1 or 0
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
 * binary_tree_size - size of binary tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 or 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}
