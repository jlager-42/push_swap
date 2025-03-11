#include "push_swap.h"

/**
 * @brief Creates a new node at the end of the stack.
 *
 * This function is responsible for creating a new node and appending it
 * to the end of the stack. It ensures that the stack maintains its 
 * structure and integrity after the new node is added.
 *
 * @param stack A pointer to the stack where the new node will be added.
 * @param value The value to be stored in the new node.
 * @return int Returns 0 on success, or a non-zero error code on failure.
 */
static void append_node(t_node **stack, int n)
{
	t_node	*node;
	t_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->next = NULL;
	node->value = n;
	if (!(*stack))
	{
		*stack = node;
		node->value = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node
	}
}


//free_errors


//error_syntax


//error_dupe

void 	check_and_set_stack(t_node **stack_a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(stack_a, argv, flag_argc);
		n = ft_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(stack_a, argv, flag_argc);
		if (error_dupe(*a, (int)n))
			free_errors(stack_a, argv, flag_argc);
		append_node(stack_a, (int)n)
		i++;
	}
}
