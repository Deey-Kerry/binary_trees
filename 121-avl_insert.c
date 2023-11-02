#include "binary_trees.h"
/**
 * r_insert_node - inserting a node in a AVL
 * @tree: type **pointer of root node of the AVL tree struct
 * @parent: parent node
 * @new: new pointer
 * @nval: insertion value
 * Return: pointer to the new node or NULL
 */
avl_t *r_insert_node(avl_t **tree, avl_t *parent, avl_t **new, int nval)
{
	int new_val;

	if (!*tree)
		return (*new = binary_tree_node(parent, nval));
	if ((*tree)->n > nval)
	{
		(*tree)->left = r_insert_node(&(*tree)->left, *tree, new, nval);
		if (!(*tree)->left)
			return (NULL);
	}
	else if ((*tree)->n < nval)
	{
		(*tree)->right = r_insert_node(&(*tree)->right, *tree, new, nval);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	new_val = binary_tree_balance(*tree);
	if (new_val > 1 && (*tree)->left->n > nval)
	{
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (new_val > 1 && (*tree)->left->n < nval)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (new_val < -1 && (*tree)->right->n < nval)
	{
		*tree = binary_tree_rotate_left(*tree);
	}
	else if (new_val < -1 && (*tree)->right->n > nval)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}

/**
 * avl_insert - a function that inserts a value in an AVL Tree
 * @tree:  double pointer to the root node of the AVL tree for
 * inserting the value
 * @value: value to store in the node to be inserted
 * Return:  pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new;

	new = NULL;

	if (!*tree)
		return (*tree = binary_tree_node(NULL, value));

	r_insert_node(tree, *tree, &new, value);
	return (new);
}
