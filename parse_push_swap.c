void push(t_node **stack, int value) 
{
    t_node *node = create_node(value);
    node->next = *stack;
    *stack = node;
}

void push_number(t_node **stack_a, int *num, int *sign, int *in_number)
{
	if (*in_number)
	{
		push(stack_a, (*num) * (*sign));
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
                push_number(stack_a, &num, NULL, NULL);
            }
            free(numbers[j]);
            j++;
        }
		free(numbers);
		i++;
	}
}
