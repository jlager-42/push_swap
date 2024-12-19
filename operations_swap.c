// swap the first 2 elements at the top of stack
// sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
// sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
// ss : sa and sb at the same time.

void sa(t_node **a) 
{
    if (!*a || !(*a)->next) return;
    t_node *first = *a;
    t_node *second = (*a)->next;
    first->next = second->next;
    second->next = first;
    *a = second;
}