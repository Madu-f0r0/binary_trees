#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a binary tree node
 * @node: a pointer to the node whose sibling is to be found
 *
 * Return: a pointer to the sibling; NULL if not available
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node == node->parent->left)
		return (node->parent->right);

	if (node == node->parent->right)
		return (node->parent->left);

	return (NULL);
}
