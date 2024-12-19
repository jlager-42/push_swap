
t_node *create_node(int value) 
{
    t_node *node = malloc(sizeof(t_node));
    if (!node) 
	{
        ft_printf("Failed to allocate memory");
		free_stack(&stack_a);
		free_stack(&stack_b);
		return (0);
    }
    node->value = value;
    node->next = NULL;
    return (node);
}


int main(int argc, char **argv)
{
	t_node *stack_a;
	t_node *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
	{
		fprintf(stderr, "Error: Not enough arguments\n");
		free_stack(&stack_a);
		free_stack(&stack_b);
		return (1);
	}
	parse_numbers(argc, argv, &stack_a);
	sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
