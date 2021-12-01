#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a new binary tree node in the right
 * @parent: Pointer to the parent node of the node to create
 * @value: Value to put in the new node
 * Return: A pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;
	binary_tree_t *tmp = NULL;

	if (!parent)
		return (NULL);

	new_node = binary_tree_node(parent, value);

	if (parent->right)
	{
		tmp = parent->right;
		tmp->parent = new_node;
		new_node->right = tmp;
		parent->right = new_node;
		return (new_node);
	}
	parent->right = new_node;
	return (new_node);
}
