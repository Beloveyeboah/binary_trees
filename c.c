#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: the pointer to the node
 * Return: 1
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if ((tree->left != NULL && binary_tree_is_complete(tree->left)) ||
			(tree->right != NULL &&  binary_tree_is_complete
			 (tree->right)))
		return (1);
	if (tree->left != NULL && tree->right == NULL)
		return (0);
	if (tree->left == NULL && tree->right != NULL)
	{
		return (0);
	}
	return (0);
}
