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


