#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "/ft_printf/ft_printf.h"
# include "/libft/libft.h"


typedef struct s_node 
{
    int				value;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheep;
	struct s_node	*target;
    struct s_node	*next;
	struct s_node	*prev;
} t_node;

//Initialize stack

//Initialize nodes

//Checks

//Operations
void			sa(t_stack_node **a, bool checker);
void			sb(t_stack_node **b, bool checker);
void			ss(t_stack_node **a, t_stack_node **b, bool checker);
void			ra(t_stack_node **a, bool checker);
void			rb(t_stack_node **b, bool checker);
void			rr(t_stack_node **a, t_stack_node **b, bool checker);
void			rra(t_stack_node **a, bool checker);
void			rrb(t_stack_node **b, bool checker);
void			rrr(t_stack_node **a, t_stack_node **b, bool checker);
void			pa(t_stack_node **a, t_stack_node **b, bool checker);
void			pb(t_stack_node **b, t_stack_node **a, bool checker);


#endif