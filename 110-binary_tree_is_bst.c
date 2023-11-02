#include "binary_trees.h"
#include <stdbool.h>
#include <limits.h>

bool is_bst_util(const binary_tree_t *tree, int min_val,
		int max_val);

/**
 * is_bst_util - find max or min
 * @max_val: maximum valie
 * @min_val: the minimum value
 * @tree: the root pointer
 * Return: nst
 */
bool is_bst_util(const binary_tree_t *tree, int min_val,
		int max_val)
{
	if (tree == NULL)
		return (true);
	if (tree->n < min_val || tree->n > max_val)
		return (false);
	return (is_bst_util(tree->left, min_val, tree->n - 1) &&
			is_bst_util(tree->right, tree->n + 1,
				max_val));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid
 * @tree: the root pointer
 * Return: 1
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_util(tree, INT_MIN, INT_MAX));
}
