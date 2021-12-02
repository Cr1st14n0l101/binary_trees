#include "binary_trees.h"

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
 * binary_tree_levelorder - goes through a binary tree
 * using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 * Return: Void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height = 0, levels = 0;

	if (!tree || !func)
		return;

	height = binary_tree_depth(tree);
	for (; levels <= height; levels++)
		level_recursively(tree, func, levels);
}

/**
 * level_recursively - Prints the number of the node recursively
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 * @level: The level in the tree
 * Return: Void
 */
void level_recursively(const binary_tree_t *tree, void (*func)(int), int level)
{
	if ((!level) == 1) /*(!levels) returns 1 if level is equals to 0*/
		func(tree->n);
	else
	{
		level_recursively(tree->left, func, level - 1);
		level_recursively(tree->right, func, level - 1);
	}
}
