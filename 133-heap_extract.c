#include "binary_trees.h"

/**
 * tree_height - checks the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: 1 or 0 if tree is NULL
 */
size_t tree_height(const heap_t *tree)
{
	size_t height_l = 0, height_r = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		height_l = 1 + tree_height(tree->left);

	if (tree->right)
		height_r = 1 + tree_height(tree->right);

	if (height_l > height_r)
		return (height_l);

	return (height_r);
}
/**
 * tree_size_h -  checks the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: 1 or 0 if tree is NULL
 */
size_t tree_size_h(const binary_tree_t *tree)
{
	size_t height_l = 0, height_r = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		height_l = 1 + tree_size_h(tree->left);

	if (tree->right)
		height_r = 1 + tree_size_h(tree->right);

	return (height_l + height_r);
}

/**
 * _preorder - function that goes through a binary tree using
 * pre-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @node: last note in traverse
 * @height: height of tree
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;
	height--;

	_preorder(tree->left, node, height);
	_preorder(tree->right, node, height);
}

/**
 * heapify - a function that heapifies max binary heap
 * @root: pointer to binary heap
 */
void heapify(heap_t *root)
{
	int val;
	heap_t *temp1, *temp2;

	if (!root)
		return;

	temp1 = root;

	while (1)
	{
		if (temp1->left == NULL)
			break;
		if (temp1->right == NULL)
			temp2 = temp1->left;
		else
		{
			if (temp1->left->n > temp1->right->n)
				temp2 = temp1->left;
			else
				temp2 = temp1->right;
		}
		if (temp1->n > temp2->n)
			break;
		val = temp1->n;
		temp1->n = temp2->n;
		temp2->n = val;
		temp1 = temp2;
	}
}

/**
 * heap_extract - function that extracts the root node of a
 * Max Binary Heap
 * @root: a double pointer to the root node of heap
 * Return: 1 or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int val;
	heap_t *heap_r, *node;

	if (!root || !*root)
		return (0);
	heap_r = *root;
	val = heap_r->n;
	if (!heap_r->left && !heap_r->right)
	{
		*root = NULL;
		free(heap_r);
		return (val);
	}

	_preorder(heap_r, &node, tree_height(heap_r));

	heap_r->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(heap_r);
	*root = heap_r;
	return (val);
}
