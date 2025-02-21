#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
    long            nbr;
    long            index;
    struct s_stack  *next;
    struct s_stack  *prev;
}   t_stack;

/* Basic stack operations */
t_stack *create_node(long number);
void    stack_add_front(t_stack **stack, t_stack *new);
void    stack_add_back(t_stack **stack, t_stack *new);
t_stack *stack_pop(t_stack **stack);
void    free_stack(t_stack **stack);

/* Required operations */
void    sa(t_stack **a);
void    sb(t_stack **b);
void    ss(t_stack **a, t_stack **b);
void    pa(t_stack **a, t_stack **b);
void    pb(t_stack **a, t_stack **b);
void    ra(t_stack **a);
void    rb(t_stack **b);
void    rr(t_stack **a, t_stack **b);
void    rra(t_stack **a);
void    rrb(t_stack **b);
void    rrr(t_stack **a, t_stack **b);

#endif