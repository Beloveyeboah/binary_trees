#include "binary_trees.h"

/**
 * binary_trees_ancestor -  finds the lowest common ancestor of two nodes
 * @first: the first pointer
 * @second: the second pointer
 * Return: 1
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *result;

	if (!first || !second)
		return (NULL);
	if (first == second || first == second->parent ||
			first->parent == second)
		return ((binary_tree_t *) first);
	if (first->parent != NULL && first->parent == second->parent)
		return ((binary_tree_t *) first->parent);
	result = binary_trees_ancestor(first->parent, second->parent);
	if (result != NULL)
		return (result);
	if (first->parent != NULL)
		return (binary_trees_ancestor(first->parent, second));
	else
		return (binary_trees_ancestor(first, second->parent));
}
