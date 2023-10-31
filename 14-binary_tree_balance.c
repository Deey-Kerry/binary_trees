#include "binary_trees.h"
/**
 * binary_tree_balance - a function that measures the balance factor
 * of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance
 * factor
 * Return: If tree is NULL, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int right = 0, left = 0, total = 0;

	if (tree)
	{
		left = ((int)binary_tree_height_b(tree->left));
		right = ((int)binary_tree_height_b(tree->right));
		total = left - right;
	}

	return (total);
}

/**
 * binary_tree_height - checks for the height of the binary tree
 * @tree: pointer to the root node of the tree to measure the
 * balance * factor
 * Return: If tree is NULL, return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (!tree)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			l = tree->left ? 1 + binary_tree_height_b(tree->left) : 1;
			r = tree->right ? 1 + binary_tree_height_b(tree->right) : 1;
		}
		return ((l > r) ? l : r);
	}
}
