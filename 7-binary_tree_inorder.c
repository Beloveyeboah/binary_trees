#include "binary_trees.h"

/**
 * binary_tree_inorder - tranverse  from inordeer
 * @tree: pointer to the root
 * @func: pointer to the func call
 * Return: anything
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}