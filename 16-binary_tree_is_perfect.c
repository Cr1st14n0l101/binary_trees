#include "binary_trees.h"
#include <stdbool.h>

/**
 * binary_tree_depth - measures the depth of a node in binary tree
 * @tree: Pointer to the root node of the tree to measure the depth
 * Return: The detph
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	height_l = tree->left ? 1 + binary_tree_depth(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_depth(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * is_perfect - Verify if a tree is perfect
 * @root: Pointer to the root node of the tree
 * @depth: The depth of the tree
 * @level: Current level in the tree
 * Return: 1 if is perfect or 0 otherwise
 */
bool is_perfect(const binary_tree_t *root, int depth, int level)
{
	if (root == NULL)
		return (true);

	if (root->left == NULL && root->right == NULL)
		return (depth == level + 1 ? false : true);

	if (root->left == NULL || root->right == NULL)
		return (false);

	return (is_perfect(root->left, depth, level + 1) &&
		is_perfect(root->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * Return: If a binary tree is perfect or 0 if it's NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth = 0;

	if (!tree)
		return (0);

	depth = binary_tree_depth(tree);
	printf("%d, %d\n", is_perfect(tree, depth, 0), depth);
	if (is_perfect(tree, depth, 0) == true)
		return (1);
	else
		return (0);
	return (0);
}
