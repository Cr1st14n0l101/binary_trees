#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 * @node: Pointer to the node to find the sibling
 * Return: The sibling of a node
 *         If node is NULL or the parent is NULL, return NULL
 *         If node has no sibling, return NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if ((node == node->parent->left) && node->parent->right)
		return (node->parent->right);
	else if ((node == node->parent->right) && node->parent->left)
		return (node->parent->left);
	return (NULL);
}
