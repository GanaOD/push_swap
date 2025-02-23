/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:22:52 by go-donne          #+#    #+#             */
/*   Updated: 2025/02/23 16:20:22 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
    long            nbr;
    long            index;
    struct s_stack  *next;
    struct s_stack  *prev;
}   t_stack;

/* Stack initialization and memory management */
t_stack *create_node(long number);
void    stack_add_front(t_stack **stack, t_stack *new);
void    stack_add_back(t_stack **stack, t_stack *new);
t_stack *stack_pop(t_stack **stack);
void    free_stack(t_stack **stack);

/* Stack utility functions */
int     stack_size(t_stack *stack);
t_stack *find_min(t_stack *stack);
t_stack *find_max(t_stack *stack);
int     is_sorted(t_stack *stack);
int     get_position(t_stack *stack, t_stack *node);

/* Required operations */
// swap.c
void    sa(t_stack **a);
void    sb(t_stack **b);
void    ss(t_stack **a, t_stack **b);

// push.c
void    pa(t_stack **a, t_stack **b);
void    pb(t_stack **a, t_stack **b);

// rot.c
void rotate(t_stack **stack);
void ra(t_stack **a);
void rb(t_stack **b);
void rr(t_stack **a, t_stack **b);

// rev.c  
void reverse_rotate(t_stack **stack);
void rra(t_stack **a);
void rrb(t_stack **b);
void rrr(t_stack **a, t_stack **b);

/* Sorting functions */
void    sort_three(t_stack **a);
void    sort_four(t_stack **a, t_stack **b);
void    sort_five(t_stack **a, t_stack **b);
void    sort_small(t_stack **a, t_stack **b);

#endif