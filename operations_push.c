// move top element from one stack to the other
// pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
// pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_node	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

void	pa(t_node **a, t_node **b)
{
	push(a, b); 
	ft_printf("pa\n");
}

void	pB(t_node **a, t_node **b)
{
	push(b, a); 
	ft_printf("pb\n");
}