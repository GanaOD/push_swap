/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:39:26 by go-donne          #+#    #+#             */
/*   Updated: 2025/02/22 13:41:38 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// core stack operations
// create new node
t_stack *create_node(long number)
{
    t_stack *new;

    new = (t_stack *)malloc(sizeof(t_stack));
    if (!new)
        return (NULL);
    new->nbr = number;
    new->index = 0;
    new->next = NULL;
    new->prev = NULL;
    return (new);
}

// Add node to front of stack
void stack_add_front(t_stack **stack, t_stack *new)
{
    if (!new)
        return;
    if (!*stack)
    {
        *stack = new;
        return;
    }
    new->next = *stack;
    new->prev = NULL;
    (*stack)->prev = new;
    *stack = new;
}

// Add node to back of stack
void stack_add_back(t_stack **stack, t_stack *new)
{
    t_stack *last;

    if (!new)
        return;
    if (!*stack)
    {
        *stack = new;
        return;
    }
    last = *stack;
    while (last->next)
        last = last->next;
    last->next = new;
    new->prev = last;
    new->next = NULL;
}

// Remove and return top node
t_stack *stack_pop(t_stack **stack)
{
    t_stack *top;

    if (!*stack)
        return (NULL);
    top = *stack;
    *stack = (*stack)->next;
    if (*stack)
        (*stack)->prev = NULL;
    top->next = NULL;
    top->prev = NULL;
    return (top);
}

// Free entire stack
void free_stack(t_stack **stack)
{
    t_stack *current;
    t_stack *next;

    if (!stack || !*stack)
        return;
    current = *stack;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *stack = NULL;
}
