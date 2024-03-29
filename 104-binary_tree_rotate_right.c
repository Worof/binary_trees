#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Description: This function performs a right rotation on a binary tree
 * starting from the given root node. The left child of the root becomes
 * the new root of the tree, and the original root becomes the right child
 * of the new root. This operation is crucial in maintaining balanced binary
 * search trees.
 *
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root = NULL;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	new_root = tree->left;
	tree->left = new_root->right;
	if (new_root->right != NULL)
		new_root->right->parent = tree;

	new_root->right = tree;
	new_root->parent = tree->parent;
	tree->parent = new_root;

	return (new_root);
}
