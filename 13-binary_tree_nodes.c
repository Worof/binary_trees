#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree.
 * @tree: A pointer to the root node of the tree to count the number of nodes.
 *
 * Return: The number of nodes with at least 1 child.
 *         If tree is NULL, the function must return 0.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Check if it's a node with at least one child */
	if (tree->left != NULL || tree->right != NULL)
		/* Count the node and recursively count in both subtrees */
		return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));

	/* If it has no children, don't count the node but continue to explore */
	return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}
