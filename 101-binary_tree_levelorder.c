#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder goes through binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node's value
 *
 * Description: If tree or func is NULL, do nothing. This function utilizes
 * a queue to keep track of nodes at the current level before moving on to
 * the next level in the tree.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *temp;
	const binary_tree_t **queue;
	size_t queue_size, queue_head = 0, queue_tail = 0;

	if (!tree || !func)
		return;

	queue_size = binary_tree_size(tree) + 1;
	queue = malloc(sizeof(*queue) * queue_size);
	if (!queue)
		return;

	queue[queue_tail++] = tree;
	while (queue_head < queue_tail)
	{
		temp = queue[queue_head++];
		func(temp->n);
		if (temp->left)
			queue[queue_tail++] = temp->left;
		if (temp->right)
			queue[queue_tail++] = temp->right;
	}
	free(queue);
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: The size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
