#include "push_swap.h"

t_node *find_max()

t_node *find_min(t_node *stack)
{
	long	minimum;
	t_node	min_node;

	if (!stack)
		return (NULL);
	minimum = LONG_MAX;
	while (stack)
	{
		if (stack->value < minimum)
		{
			minimum = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

static void append_node (t_node **stack, int n)
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

void set_stack_a(t_node **stack_a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(stack_a);
		n = ft_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(stack_a)
		append_node(stack_a, (int)n)
		i++;
	}
}
