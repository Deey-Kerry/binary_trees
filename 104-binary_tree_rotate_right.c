#include "binary_trees.h"
/**
 * binary_tree_rotate_right - function that performs a right-rotation
 * on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *p;

	if (!tree || !tree->left)
		return (NULL);

	p = tree->left;
	tree->left = p->right;

	if (p->right)
		p->right->parent = tree;

	p->right = tree;
	p->parent = tree->parent;
	tree->parent = p;
	return (p);
}
