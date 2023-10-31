#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: is a pointer to the root node of the tree to measure ths size
 *
 * Return: the size, otherwise 0.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree == NULL)
		return (count);

	count++;
	count += binary_tree_size(tree->left);
	count += binary_tree_size(tree->right);

	return (count);
}
