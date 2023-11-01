#include "binary_trees.h"
/**
 * binary_tree_is_perfect -  a function that checks if a binary tree
 * is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: If tree is NULL, your function must return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t h = 0, p = 0, nodes = 0;

	if (tree == NULL)
		return (0);
	if (!tree->right && !tree->left)
		return (1);

	h = binary_tree_height(tree);
	nodes = binary_tree_size(tree);

	p = (size_t)_pow_recursion(2, h + 1);
	return (p - 1 == nodes);
}

/**
 * _pow_recursion - function for recursion
 * @x: exponential value
 * @y: power to raise to
 * Return: x raised to y
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	else
		return (x * _pow_recursion(x, y - 1));
}

/**
 * binary_tree_size - size of the binary tree
 * @tree: pointer to the root node of the tree to check
 * Return: size of binary tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_height - height of tree
 * @tree: pointer to the root node of the tree to check
 * Return: height of tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0, height_r = 0;

	if (tree == NULL)
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}
