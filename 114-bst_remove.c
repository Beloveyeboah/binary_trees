#include "binary_trees.h"

bst_t *find_min(bst_t *node);

/**
 * find_min - used to find mininum
 * @node: the pointer
 * Return: 1
 */
bst_t *find_min(bst_t *node)
{
	bst_t *current = node;

	while (current && current->left)
	{
		current = current->left;
	}
	return (current);
}



/**
 * bst_remove - removes a node from a Binary Search Tree
 * @value: thedata
 * @root: the pointer to binary
 * Return: 1
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp, *suc;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
	{
		root->left = bst_remove(root->left, value);
	}
	else if (value > root->n)
	{
		root->right = bst_remove(root->right, value);
	}
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		suc = find_min(root->right);
		root->n = suc->n;
		root->right = bst_remove(root->right, suc->n);
	}
	return (root);
}
