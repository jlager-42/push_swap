// bottom to top
// rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
// rrr : rra and rrb at the same time.

void rra(t_node **a) 
{
    if (!*a || !(*a)->next) return;
    t_node *prev = NULL;
    t_node *current = *a;
    while (current->next) {
        prev = current;
        current = current->next;
    }
    current->next = *a;
    *a = current;
    prev->next = NULL;
}