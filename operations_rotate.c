// top to bottom
// ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
// rr : ra and rb at the same time.

void ra(t_node **a)
{
    if (!*a || !(*a)->next)
		return;
    t_node *first = *a;
    t_node *current = *a;

    while (current->next)
        current = current->next;
    *a = first->next; // Move the head to the next node
    first->next = NULL; // Detach the first node
    current->next = first; // Link the first node to the end
}

void rb(t_node **b)
{
    if (!*b || !(*b)->next) return;
    t_node *first = *b;
    t_node *current = *b;

    while (current->next)
        current = current->next;
    *b = first->next; // Move the head to the next node
    first->next = NULL; // Detach the first node
    current->next = first; // Link the first node to the end
}

void rr(t_node **a, t_node **b)
{
    if (a && *a && (*a)->next)
        ra(a);
    if (b && *b && (*b)->next)
        rb(b);
}