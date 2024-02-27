#include "binary_trees.h"

/**
 * binary_tree_inorder - Goes through a binary tree using in-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node's value.
 *
 * Description: If tree or func is NULL, do nothing. This function recursively
 * traverses the tree in an in-order manner,
 * meaning it visits the left subtree,
 * the root node,
 * and then the right subtree, applying the func to each node's value.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_inorder(tree->left, func); /* Process the left subtree */
	func(tree->n);                         /* Apply func to the current node */
	binary_tree_inorder(tree->right, func);/* Process the right subtree */
}
