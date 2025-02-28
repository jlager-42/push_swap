// bottom to top
// rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
// rrr : rra and rrb at the same time.

static void reverse_rotate(t_node **stack)
{
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void rra(t_node **a) 
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void rrb(t_node **b) 
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(a);
	ft_printf("rrr\n");
}