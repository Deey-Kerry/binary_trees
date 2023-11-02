#include "binary_trees.h"
/**
 * binary_tree_is_avl - a function that checks if a binary tree is a
 * valid AVL Tree
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 or 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (btia_helper(tree, INT_MIN, INT_MAX));
}

/**
 * btia_helper - helps find a binary tree
 * @tree: a pointer to the root node of the tree to check
 * @min: minimum
 * @max: maximum
 * Return: 1 or 0
 */
int btia_helper(const binary_tree_t *tree, int min, int max)
{
	int path_left, path_right;

	if (tree == NULL)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	path_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	path_right = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	if (abs(path_left - path_right) > 1)
		return (0);

	return (btia_helper(tree->left, min, tree->n - 1) &&
			btia_helper(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_height - height of binary tree
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 or 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0, height_right = 0;

	if (tree == NULL)
		return (0);

	height_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_right = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (height_left > height_right ? height_left : height_right);
}
