// move top element from one stack to the other
// pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
// pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

void push(t_node **stack, int value) 
{
    t_node *node = create_node(value);
    node->next = *stack;
    *stack = node;
}

void pa(t_node **a, t_node **b) {
    if (is_empty(*b)) return;
    push(a, pop(b));
}

void pb(t_node **a, t_node **b) {
    if (is_empty(*a)) return;
    push(b, pop(a));
}