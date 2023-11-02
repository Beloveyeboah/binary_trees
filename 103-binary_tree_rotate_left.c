#include "binary_trees.h"

/**
 * binary_tree_rotate_left -  performs a left-rotation on a binary tree
 * @tree: the pointer to thr root
 * Return: 1
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot = NULL;

	if (tree == NULL)
		return (NULL);
	pivot = tree->right;
	if (pivot == NULL)
		return (tree);
	tree->right = pivot->left;
	if (pivot->left != NULL)
		pivot->left->parent = tree;
	pivot->left = tree;
	pivot->parent = tree->parent;
	tree->parent = pivot;

	return (pivot);
}
