#include "binary_trees.h"

/**
 * zero_or_two_kids - checks if all the nodes of a binary tree have 0 or 2 kids
 * @tree: a pointer to the tree to be checked
 *
 * Return: 1 if true; 0 if not
 */
int zero_or_two_kids(const binary_tree_t *tree)
{
	int left_zt, right_zt;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	left_zt = zero_or_two_kids(tree->left);
	right_zt = zero_or_two_kids(tree->right);

	if (left_zt && right_zt)
		return (1);
	else
		return (0);
}

/**
 * binary_tree_depth - measures the depth of a node in a binary tree.
 * @tree: a pointer to the node to measure the depth
 *
 * Return: depth, otherwise 0.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree == NULL)
		return (0);

	while (tree->parent != NULL)
	{
		tree = tree->parent;
		count++;
	}

	return (count);
}

/**
 * same_depth_leaves - checks if all the leaf nodes are at the same depth
 * @tree: a pointer to the tree to be checked
 * @depth: the depth of the first leaf
 * @same_or_not: checks if the depth of the current leaf is same as the first
 *
 * Return: 1 if all the leaf nodes are at the same depth; 0 if not
 */
int same_depth_leaves(const binary_tree_t *tree, int *depth, int *same_or_not)
{
	int new_depth = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
	{
		new_depth = binary_tree_depth(tree);

		if (*depth == 0)
		{
			*depth = new_depth;
			return (1);
		}

		else
		{
			if (new_depth == *depth)
				return (1);
			else
				return (0);
		}
	}

	*same_or_not = same_depth_leaves(tree->left, depth, same_or_not);
	if (*same_or_not == 0)
		return (0);

	*same_or_not = same_depth_leaves(tree->right, depth, same_or_not);
	if (*same_or_not == 0)
		return (0);

	return (1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the tree to be checked
 *
 * Return: 1 if the tree is perfect; 0 if not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int zero_or_two, depth = 0, same_or_not = 0;

	if (tree == NULL)
		return (0);

	/* Check if each node has zero or 2 child nodes */
	zero_or_two = zero_or_two_kids(tree);

	if (zero_or_two)
	{
		return (same_depth_leaves(tree, &depth, &same_or_not));
	}

	return (0);
}
