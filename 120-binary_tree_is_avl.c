#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);

/**
 * binary_tree_height - checks the height
 * @tree: the pointer
 * Return: 1
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (-1);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	return (1 + (left > right ? left : right));
}
 
/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: the pointer
 * Return: 1
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left, right, balance;

	if (tree == NULL)
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	balance = left - right;
	if (balance > 1 || balance < -1)
		return (0);

	if (!binary_tree_is_avl(tree->left) ||
			!binary_tree_is_avl(tree->right))
		return (0);
	return (1);
}
