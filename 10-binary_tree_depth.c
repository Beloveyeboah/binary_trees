#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t dep = 0;

	if (tree == NULL)
		return (dep);
	while (tree->parent != NULL)
	{
		dep++;
		tree = tree->parent;
	}
	return (dep);
}
