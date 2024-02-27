#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: pointer to the root node of the tree to delete
 *
 * Description: If tree is NULL, do nothing. Recursively
 * delete nodes from the binary tree.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

    /* Recursively delete left and right subtrees */
binary_tree_delete(tree->left);
binary_tree_delete(tree->right);

    /* Delete current node */
free(tree);
}
