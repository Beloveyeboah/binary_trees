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
	const binary_tree_t *first_parent;
	const binary_tree_t *second_parent;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *) first);
	first_parent = first->parent;
	second_parent = second->parent;
	while (first_parent)
	{
		if (first_parent == second)
			return ((binary_tree_t *) first_parent);
		second_parent = second->parent;

		while (second_parent == first)
		{
			if (second_parent == first)
				return ((binary_tree_t *) second_parent);
			second_parent = second_parent;
		}
		first_parent = first_parent->parent;
	}
	return (NULL);
}
