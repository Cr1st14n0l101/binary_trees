#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a new binary tree node in the left
 * @parent: Pointer to the parent node of the node to create
 * @value: Value to put in the new node
 * Return: A pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;
	binary_tree_t *tmp = NULL;

	if (!parent)
		return (NULL);

	new_node = binary_tree_node(parent, value);

	if (parent->left)
	{
		tmp = parent->left;
		tmp->parent = new_node;
		new_node->left = tmp;
		parent->left = new_node;
		return (new_node);
	}
	parent->left = new_node;
	return (new_node);
}
