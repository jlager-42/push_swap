


int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		count;
	int		string;

	if (argc < 2 || !check_input(argv))
	{
		ft_printf("\nError: Invalid input\n");
		return (0);
	}

	// outer loop is to go from argumet to argument, the inner is to split
	while (argv[count][string] && count < argc + 1)
	{

		while (argv[])
			{

			}
		push(argv[i - 1])

	}

	stack_b = NULL;
	stack_a = fill_stack_values(ac, av);
	// stack_size = get_stack_size(stack_a);
	// assign_index(stack_a, stack_size + 1);
	parse_numbers(argc, argv, &stack_a);
	sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}