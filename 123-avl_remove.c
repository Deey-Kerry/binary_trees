#include "binary_trees.h"
/**
 * bal - Checks for balance factor of a AVL
 * @tree: pointer to the root node of the tree where you will remove a node
 * Return: balance
 */
void bal(avl_t **tree)
{
	int new_val;

	if (!tree || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	bal(&(*tree)->left);
	bal(&(*tree)->right);
	new_val = binary_tree_balance((const binary_tree_t *)*tree);
	if (new_val > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (new_val < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * successor - Next node after the previous nodes
 * @node: index to check
 * Return: min value
 */
int successor(bst_t *node)
{
	int left = 0;

	if (!node)
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
 * remove_type - removes a node depending of its children
 * @root: pointer to the root node of the tree where you will remove a node
 * Return: 0 or 1
 *
 */
int remove_type(bst_t *root)
{
	int n_value = 0;

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
	{
		n_value = successor(root->right);
		root->n = n_value;
		return (n_value);
	}
}

/**
 * bst_remove - removes a node
 * @root: pointer to the root node of the tree where you will
 * remove a node
 * @value: node with this value to remove
 * Return: changed tree
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

/**
 * avl_remove - a function that removes a node from an AVL tree
 * @root: pointer to the root node of the tree for removing a node
 * @value: value to remove in the tree
 * Return:  pointer to the new root node of the tree after removing
 * the desired value, and after rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (!root_a)
	{
		return (NULL);
	}

	bal(&root_a);
	return (root_a);
}
