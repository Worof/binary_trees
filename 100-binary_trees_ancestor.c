#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node of the two nodes,
 *         or NULL if no common ancestor was found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *temp_first = first, *temp_second = second;

	while (temp_first)
	{
		temp_second = second;
		while (temp_second)
		{
			if (temp_first == temp_second)
				return ((binary_tree_t *)temp_first);
			temp_second = temp_second->parent;
		}
		temp_first = temp_first->parent;
	}
	return (NULL);
}
