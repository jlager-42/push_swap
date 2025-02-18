int get_stack_head(t_node *stack)
{
    if (!stack)
	{
        ft_printf("Stack is empty.\n");
        return 0;
	}
    return stack->value;
}

int sum_numbers(t_node *head) 
{
    int sum = 0;
    while (head != NULL) 
	{
        sum += head->number;
        head = head->next;
    }
    return sum;
}