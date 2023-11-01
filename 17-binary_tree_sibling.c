#include "binary_trees.h"


/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: the pointer to hte root node
 * Return: 1
 *
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (node == NULL || node->parent == NULL)
		return (NULL);
	parent = node->parent;
	if (parent->left == node)
		return (parent->right);
	else
		return (parent->left);
}
