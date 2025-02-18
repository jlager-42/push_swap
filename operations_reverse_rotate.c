// bottom to top
// rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
// rrr : rra and rrb at the same time.

void rra(t_node **a) 
{
    if (!*a || !(*a)->next)
		return;
    t_node *prev = NULL;
    t_node *current = *a;
    while (current->next)
	{
        prev = current;
        current = current->next;
    }
    current->next = *a;
    *a = current;
    prev->next = NULL;
}

void rrb(t_node **b)
{
    if (!*b || !(*b)->next)
		return;
    t_node *prev = NULL;
    t_node *current = *b;

    // Traverse to the last node
    while (current->next) 
	{
        prev = current;
        current = current->next;
    }
    current->next = *b;  // Link the last node to the head
    *b = current;        // Update the head to the last node
    prev->next = NULL;   // Detach the last node from its previous position
}

void rrr(t_node **a, t_node **b)
{
    if (a && *a && (*a)->next)
        rra(a);
    if (b && *b && (*b)->next)
        rrb(b);
}