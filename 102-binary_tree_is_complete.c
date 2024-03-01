#include "binary_trees.h"
#include <stdlib.h>

/**
 * queue_push - Pushes a node to the queue
 * @queue: Double pointer to the head of the queue
 * @node: Pointer to the binary tree node to push to the queue
 *
 * Return: Pointer to the created queue node, or NULL on failure
 */
static binary_tree_t **queue_push(binary_tree_t **queue, binary_tree_t *node)
{
	while (*queue)
		queue++;
	*queue = node;
	return (queue + 1);
}

/**
 * queue_pop - Pops a node from the queue
 * @queue: Double pointer to the head of the queue
 *
 * Return: Pointer to the node that was popped
 */
static binary_tree_t *queue_pop(binary_tree_t **queue)
{
	binary_tree_t *node = *queue;

	while (*queue)
	{
		*queue = *(queue + 1);
		queue++;
	}
	return (node);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *queue[1024] = {NULL}, **queue_head = queue, *node = NULL;
	int flag = 0;

	if (!tree)
		return (0);

	queue_head = queue_push(queue_head, (binary_tree_t *)tree);
	while ((node = queue_pop(queue)) != NULL)
	{
		if (!node)
		{
			flag = 1;
		}
		else
		{
			if (flag)
				return (0); /* Found a node after a NULL node */
			queue_head = queue_push(queue_head, node->left);
			queue_head = queue_push(queue_head, node->right);
		}
	}
	return (1);
}
