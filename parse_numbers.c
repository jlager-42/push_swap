t_node *create_node(int num) 
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

void push_numbers(t_node **stack_a, int *num, int *sign, int *in_number)
{
    if (*in_number)
    {
        t_node *node = create_node((*num) * (*sign));
        node->next = *stack;
        *stack = node;

        *num = 0;
        *sign = 1;
        *in_number = 0;
    }
}

void parse_numbers(int argc, char **argv, t_node **stack_a)
{
	char **numbers;
	int i = 1;
	int j;
	int num;

	while (i < argc)
	{
		numbers = ft_split(argv[i], ' ');
		if (!numbers)
			return(1);
		j = 0;
		while (numbers[j])
        {
            if ((numbers[j][0] >= '0' && numbers[j][0] <= '9') || numbers[j][0] == '+' || numbers[j][0] == '-')
            {
                num = ft_atoi(numbers[j]);
                push(stack_a, &num, NULL, NULL);
            }
			else
			{
				free(numbers);
				return (0);
			}
            j++;
        }
		free(numbers);
		i++;
	}
}
