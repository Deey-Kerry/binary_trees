#include "binary_trees.h"
/**
 * binary_tree_height_b - checks for the height of the binary tree
 * @tree: pointer to the root node of the tree to measure the
 * balance * factor
 * Return: If tree is NULL, return 0
 */
size_t binary_tree_height_b(const binary_tree_t *tree)
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

/**
 * binary_tree_balance - a function that measures the balance factor
 * of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance
 * factor
 * Return: If tree is NULL, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int r = 0, l = 0, sum = 0;

	if (tree)
	{
		l = ((int)binary_tree_height_b(tree->left));
		r = ((int)binary_tree_height_b(tree->right));
		sum = l - r;
	}

	return (sum);
}
