#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 *
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 *
 * Description: Inserts a new node as the right child of the parent node. If the
 * parent already has a right child, the new node takes its place, and the old
 * right child is set as the right child of the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    if (parent == NULL)
        return (NULL);

    new_node = (binary_tree_t *)malloc(sizeof(binary_tree_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;  /* New node initially has no left child */
    new_node->right = parent->right;  /* Old right child becomes right child of new node */

    if (parent->right != NULL)
        parent->right->parent = new_node;

    parent->right = new_node;  /* Set new node as right child of parent */

    return (new_node);
}
