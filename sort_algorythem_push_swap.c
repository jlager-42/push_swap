

int get_stack_size(t_node *stack) {
    int size = 0;
    while (stack) {
        size++;
        stack = stack->next;
    }
    return size;
}

int get_position(t_node *stack, int value) {
    int position = 0;
    while (stack) {
        if (stack->value == value)
            return position;
        position++;
        stack = stack->next;
    }
    return -1;  // Value not found
}

t_node *find_max_node(t_node *stack) {
    t_node *max_node = stack;
    while (stack) {
        if (stack->value > max_node->value) {
            max_node = stack;
        }
        stack = stack->next;
    }
    return max_node;
}

void sort_stack(t_node **a, t_node **b) 
{
    int stack_size = get_stack_size(*a);
    int chunk_size = stack_size / 10;  // Divide the stack into 10 chunks
    int current_chunk = 1;

    // Push elements from stack A to stack B in chunks
    while (*a) 
	{
        t_node *temp = *a;
        int position = 0;
        
        // Check if the top element of stack A belongs to the current chunk
        while (temp && (temp->value > current_chunk * chunk_size)) 
		{
            position++;
            temp = temp->next;
        }

        // Move the element to the top using rotations
        if (position < stack_size / 2) 
		{
            while (position-- > 0)
                ra(a);  // Rotate stack A upwards
        }
		else 
		{
            while (position++ < stack_size)
                rra(a);  // Rotate stack A downwards
        }

        // Push the element to stack B
        pb(a, b);

        // Update chunk when all current chunk elements are pushed
        if (get_stack_size(*b) >= current_chunk * chunk_size)
            current_chunk++;
    }

    // Sort stack B and push back to stack A
    while (*b) 
	{
        t_node *max_node = find_max_node(*b);  // Find the maximum node in stack B
        int max_position = get_position(*b, max_node->value);

        // Bring the max element to the top of stack B
        if (max_position < get_stack_size(*b) / 2) 
		{
            while (max_position-- > 0)
                rb(b);  // Rotate stack B upwards
        }
		else
		{
            while (max_position++ < get_stack_size(*b))
                rrb(b);  // Rotate stack B downwards
        }

        // Push the max element back to stack A
        pa(a, b);
    }
}

