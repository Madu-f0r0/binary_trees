#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a binary tree node
 * @node: a pointer to the node whose uncle is to be found
 *
 * Return: a pointer to the uncle node; NULL if not available
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	if (node->parent == node->parent->parent->left)
		return (node->parent->parent->right);

	if (node->parent == node->parent->parent->right)
		return (node->parent->parent->left);

	return (NULL);
}
