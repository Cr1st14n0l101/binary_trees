#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 * Return: The balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int height_l = 0, height_r = 0;

	if (!tree)
		return (0);

	height_l = tree->left ? (int)binary_tree_height(tree->left) : -1;
	height_r = tree->right ? (int)binary_tree_height(tree->right) : -1;
	return (height_l - height_r);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 * Return: height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * Return: If a binary tree is perfect or 0 if it's NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (binary_tree_balance(tree->left) == binary_tree_balance(tree->right))
		return (1);
	return (0);
}
