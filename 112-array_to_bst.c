#include "binary_trees.h"
#include "binary_trees.h"

/**
 * array_to_bst - array
 * @size: the size of the array
 * @array: the array
 * Return: 1
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL, *new, *current, *parent;
	size_t i;

	if (array == NULL || size == 0)
		return (0);

	for (i = 0; i < size; i++)
	{
		new = malloc(sizeof(bst_t));
		if (new == NULL)
		{
			return (NULL);
		}
		new->n = array[i];
		new->parent = NULL;
		new->left = NULL;
		new->right = NULL;

		if (root == NULL)
		{
			root = new;
		}
		else
		{
			current = root;
			parent = NULL;
			while (current != NULL)
			{
				parent = current;
				if (array[i] < current->n)
					current = current->left;
				else if (array[i] > current->n)
					current = current->right;
				else
				{
					free(new);
					break;
				}

			}
			if (current == NULL)
			{
				if (array[i] < parent->n)
					parent->left = new;
				else
					parent->right = new;
				new->parent = parent;
			}
		}
	}
	return (root);
}
