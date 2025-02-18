int	check_input_string(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_isdigit(av[i]) || av[i] == '+' || av[i] == '-' || av[i] == '+' || av[i] == ' ')
			i++;
		else
		{
			ft_printf("\nError: Invalid input\n")
			return (0);
		}
	}
	if (have_duplicates(argv))
		return (0);
	return (1);
}

