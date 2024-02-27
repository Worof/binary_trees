#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Description: A full binary tree is a tree in which every node other than the
 * leaves has two children. This function checks recursively if a binary tree
 * meets this criterion starting from the root.
 *
 * Return: 1 if the tree is full, 0 otherwise or if tree is NULL.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	/* Check if tree is NULL */
	if (tree == NULL)
		return (0);

	/* Leaf nodes are considered full */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* Recursively check if both subtrees are full */
	if (tree->left != NULL && tree->right != NULL)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	/* If it has only one child, it's not full */
	return (0);
}
