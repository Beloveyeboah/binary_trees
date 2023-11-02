#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: the pointer to thr root
 * @value: the data value
 * Return: 1
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *current, *parent;

	if (tree == NULL)
		return (NULL);
	new = malloc(sizeof(bst_t));
	if (new == NULL)
		return (NULL);
	new->n = value;
	new->left = NULL;
	new->right = NULL;
	new->parent = NULL;

	if (*tree == NULL)
	{
		*tree = new;
		return (new);
	}
	current = *tree;
	parent = NULL;
	while (current != NULL)
	{
		parent = current;
		if (value < current->n)
			current = current->left;
		else if (value > current->n)
			current = current->right;
		else
		{
			free(new);
			return (NULL);
		}
	}
	if (value < parent->n)
		parent->left = new;
	else
		parent->right = new;
	new->parent = parent;
	return (new);
}
