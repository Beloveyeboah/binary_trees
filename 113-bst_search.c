#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary
 * @tree: the pointer
 * @value: the data
 * Return: 1
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL || tree->n == value)
	{
		return ((bst_t *) tree);
	}
	else if (value < tree->n)
	{
		return (bst_search(tree->left, value));
	}
	else
		return (bst_search(tree->right, value));
}
