#include "binary_trees.h"

/**
 * binary_tree_size -  measures the size of a binary tree
 * @tree: the pointer to the node
 * Return: size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left = 0;
	size_t right = 0;

	if (tree == NULL)
		return (0);
	left = binary_treee_size(tree->left);
	right = binary_tree_size(tree->right);
	return (left + right + 1);
}
