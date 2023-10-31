#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the number of leaves in a binary tree
 * @tree: a pointer to the root node of the tree
 *
 * Return: The number of leaves in the tree; 0 if the tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		leaves++;

	leaves += binary_tree_leaves(tree->left);
	leaves += binary_tree_leaves(tree->right);

	return (leaves);
}
