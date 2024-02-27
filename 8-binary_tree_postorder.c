#include "binary_trees.h"

/**
 * binary_tree_postorder Goes through binary tree using post-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 *        The value in the node must be passed as a parameter to this function.
 *
 * Description: If tree or func is NULL, do nothing. This function traverses
 * the tree in a post-order manner, which means visiting the left subtree,
 * then the right subtree, and finally the current node, at each step applying
 * the func to the node's value.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_postorder(tree->left, func);  /* Process the left subtree */
	binary_tree_postorder(tree->right, func); /* Process the right subtree */
	func(tree->n);                            /* Apply func to the current node */
}
