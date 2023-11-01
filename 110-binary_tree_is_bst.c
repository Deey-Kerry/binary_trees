#include "binary_trees.h"
/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary
 * Search Tree
 * @tree:  pointer to the root node of the tree to check
 * Return: 0 or 1
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (btib_helper(tree, INT_MIN, INT_MAX));
}

/**
 * btib_helper - checks for valid binary search
 * @tree: pointer to the root node of the tree to check
 * @min: minimum search
 * @max: maximum search
 * Return: 1 or 0
 */
int btib_helper(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	return (btib_helper(tree->left, min, tree->n - 1) &&
		btib_helper(tree->right, tree->n + 1, max));
}
