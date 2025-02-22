/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:43:41 by go-donne          #+#    #+#             */
/*   Updated: 2025/02/22 14:31:09 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// to know when to use different sorting strategies
int stack_size(t_stack *stack)
{
    int count;
    
    count = 0;
    while (stack)
    {
        count++;
        stack = stack->next;
    }
    return (count);
}

t_stack *find_min(t_stack *stack)
{
    t_stack *min_node;
    
    if (!stack)
        return (NULL);
    min_node = stack;
    while (stack)
    {
        if (stack->nbr < min_node->nbr)
            min_node = stack;
        stack = stack->next;
    }
    return (min_node);
}

t_stack *find_max(t_stack *stack)
{
    t_stack *max_node;
    
    if (!stack)
        return (NULL);
    max_node = stack;
    while (stack)
    {
        if (stack->nbr > max_node->nbr)
            max_node = stack;
        stack = stack->next;
    }
    return (max_node);
}

int is_sorted(t_stack *stack)
{
    if (!stack)
        return (1);
    while (stack->next)
    {
        if (stack->nbr > stack->next->nbr)
            return (0);
        stack = stack->next;
    }
    return (1);
}

// Helper to get position of a node in stack
// Returns 0-based index from top
int get_position(t_stack *stack, t_stack *node)
{
    int pos;
    
    pos = 0;
    while (stack)
    {
        if (stack == node)
            return (pos);
        pos++;
        stack = stack->next;
    }
    return (-1);
}
