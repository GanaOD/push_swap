/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:22:27 by go-donne          #+#    #+#             */
/*   Updated: 2025/02/22 15:20:37 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap first 2 elements of stack
void swap(t_stack **stack)
{
    t_stack *first;
    t_stack *second;

    if (!*stack || !(*stack)->next)
        return;
    first = *stack;
    second = first->next;
    
    // Rewire the connections
    first->next = second->next;
    first->prev = second;
    second->next = first;
    second->prev = NULL;
    if (first->next)
        first->next->prev = first;
    *stack = second;
}

void sa(t_stack **a)
{
    swap(a);
    write(1, "sa\n", 3);
}

void sb(t_stack **b)
{
    swap(b);
    write(1, "sb\n", 3);
}

void ss(t_stack **a, t_stack **b)
{
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}
