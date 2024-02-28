#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node's parent
 * @node: A pointer to the node to find the sibling of its parent
 *
 * Return: A pointer to the sibling of the node's parent
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	binary_tree_t *parent = node->parent;

	if (parent->parent == NULL)
		return (NULL);

	if (parent->parent->left != NULL && parent->parent->left != parent)
		return (parent->parent->left);
	if (parent->parent->right != NULL && parent->parent->right != parent)
		return (parent->parent->right);

	return (NULL);
}

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: A pointer to the node to find the uncle
 *
 * Return: A pointer to the uncle node
 *         If node is NULL, return NULL
 *         If node has no uncle, return NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	return (binary_tree_sibling(node));
}
