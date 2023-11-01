#include "binary_trees.h"
/**
 * binary_trees_ancestor - function that finds the lowest common
 * ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node of the two
 * given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t d_first, d_second;

	if (!first || !second)
		return (NULL);
	d_first = binary_tree_depth(first);
	d_second = binary_tree_depth(second);

	for (; d_first > d_second; d_first--)
	{
		first = first->parent;
	}
	for (; d_second > d_first; d_second--)
	{
		second = second->parent;
	}
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}

/**
 * binary_tree_depth - depth of binary tree
 * @tree: pointer to tree
 * Return: binary tree depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t d = 0;

	if (!tree)
		return (0);
	while (tree->parent)
	{
		d++;
		tree = tree->parent;
	}
	return (d);
}
