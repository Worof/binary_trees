#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a binary tree
 * @tree: Pointer to the root node of the tree to measure the depth.
 * Return: The depth of the tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree || !tree->left)
		return (0);
	return (1 + binary_tree_depth(tree->left));
}

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if ((tree->left) && (tree->right))
		return (binary_tree_is_full(tree->left)
				&& binary_tree_is_full(tree->right));

	return (0);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
int left_depth, right_depth;

if (!tree)
return (0);

left_depth = binary_tree_depth(tree->left);
right_depth = binary_tree_depth(tree->right);

if (left_depth == right_depth && binary_tree_is_full(tree))
	return (1);

return (0);
}
