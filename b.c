#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: the pointer to the node
 * Return: 1
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int size, none;
	const binary_tree_t **queue, *node;

	if (!tree)
		return (0);
	size = 0;
	queue = malloc(sizeof(binary_tree_t *));
	if (queue == NULL)
		return (0);
	queue[size] = tree;
	size++;
	none = 0;
	while (size > 0)
	{
		node = queue[0];
		if (node->left)
		{
			if (none)
			{
				free(queue);
				return (0);
			}
			queue = realloc(queue, sizeof(binary_tree_t *) * (size + 1));
			if (queue == NULL)
				return (0);
			queue[size] = node->left;
			size++;
		}
		else
		{
			none = 1;
		}
		if (node->right)
		{
			if (none)
			{
				free(queue);
				return (0);
			}
			queue = realloc(queue, sizeof(binary_tree_t *) * (size + 1));
			if (queue == NULL)
				return (0);
			queue[size] = node->right;
			size++;
		}
		else
			none = 1;
		size--;
		queue = &queue[1];
	}
	free(queue);
	return (1);
}
