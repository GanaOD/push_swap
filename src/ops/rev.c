/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:22:21 by go-donne          #+#    #+#             */
/*   Updated: 2025/02/22 15:20:34 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// downward rotations
// rotate stack down (last element becomes first)
void reverse_rotate(t_stack **stack)
{
    t_stack *last;
    
    if (!*stack || !(*stack)->next)
        return;
    last = *stack;
    while (last->next)
        last = last->next;
    
    last->prev->next = NULL;
    last->next = *stack;
    last->prev = NULL;
    (*stack)->prev = last;
    *stack = last;
}

void rra(t_stack **a)
{
    reverse_rotate(a);
    write(1, "rra\n", 3);
}

void rrb(t_stack **b)
{
    reverse_rotate(b);
    write(1, "rrb\n", 3);
}

void rrr(t_stack **a, t_stack **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 3);
}