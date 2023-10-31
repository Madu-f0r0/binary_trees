#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: a pointer to the tree whose nodes are to be counted
 *
 * Return: the number of nodes with at least 1 child; 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree == NULL)
		return (0);

	if (tree->left || tree->right)
		nodes++;

	nodes += binary_tree_nodes(tree->left);
	nodes += binary_tree_nodes(tree->right);

	return (nodes);
}
