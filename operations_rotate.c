// top to bottom
// ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
// rr : ra and rb at the same time.

static void rotate(t_node **stack)
{
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void ra(t_node **a) 
{
	rotate(a);
	ft_printf("ra\n");
}

void rb(t_node **b) 
{
	rotate(b);
	ft_printf("rb\n");
}

void rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(a);
	ft_printf("rr\n");
}