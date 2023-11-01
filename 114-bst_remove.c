#include "binary_trees.h"
/**
 * successor - A node that replaces the previous node
 * @node: pointer to the  node
 * Return: value of binary tree
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}
}

/**
 * two_children - function that gets the next successor using the min
 * value in the right subtree
 * @root: pointer to the root node of the tree where you will remove a node
 * Return: value
 */
int two_children(bst_t *root)
{
	int new_val = 0;

	new_val = successor(root->right);
	root->n = new_val;
	return (new_val);
}

/**
 *remove_type - removes a node depending of its children
 *@root: pointer to the root node of the tree where you will remove a node
 *Return: 0 or 1
 */
int remove_type(bst_t *root)
{
	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
		return (two_children(root));
}

/**
 * bst_remove - a function that removes a node from a Binary
 * Search Tree
 * @root: pointer to the root node of the tree where you will
 * remove a node
 * @value: value to remove in the tree
 * Return:  pointer to the new root node of the tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (!root)
		return (NULL);

	if (value < root->n)
		bst_remove(root->left, value);

	else if (value > root->n)
		bst_remove(root->right, value);

	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}
