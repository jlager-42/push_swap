#include "push_swap.h"

// Turk Algorythem
// pushes from a to b untill there are only 3 left in a
// during each push b is sorted descending
// this is done by targeting a closest smaller value in b than a
// if no closest smaller is found it targets the maximum in b 
// (ex. if a value is smaller than all in b)
// >> we assing target node >> "what is the cheepest?"
// formula: 
// push_cost = x ops to get a to top + x ops to get a to target node

// once I only have 3 in a I sort a
// than I push b values back into a the opposite way like before (leaving 3)
// >> closest bigger, if not found than min

// we use the median to find where the the last values in b should go
// we ra or rra to get the remaining to the correct post


void	sort_three(t_node **stack_a)
{
	t_node	biggest;

	biggest = find_max(*stack_a);
	if (biggest == *stack_a)
		ra(stack_a);
	else if ((*stack_a)->next == biggest)
		rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

void	sort_stacks(t_node **a, t_stack_node **b)
{
	int	length_a;

	lenght_a = stack_len(*a);
	if (length_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if (length_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while (length_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b	= NULL;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	parse_stack_a(&stack_a, argv + 1);
	if (!stack_sorted(stack_a))
	{
		if (stack_lenght(stack_a) == 2)
			sa(&a, false);
		else if (stack_length(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_stacks(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	return (0);
}