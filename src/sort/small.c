/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:49:22 by go-donne          #+#    #+#             */
/*   Updated: 2025/02/23 16:13:14 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_stack **a)
{
    int first;
    int second; 
    int third;

    if (!*a || !(*a)->next || !(*a)->next->next)
        return;
    first = (*a)->nbr;
    second = (*a)->next->nbr;
    third = (*a)->next->next->nbr;
    
    if (first > second && second < third && first < third)
        sa(a);
    else if (first > second && second > third)
    {
        sa(a);
        rra(a);
    }
    else if (first > second && second < third && first > third)
        ra(a);
    else if (first < second && second > third && first < third)
    {
        sa(a);
        ra(a);
    }
    else if (first < second && second > third && first > third)
        rra(a);
}

void sort_five(t_stack **a, t_stack **b)
{
    t_stack *min;
    int pos;

    if (!*a || stack_size(*a) != 5)
        return;

    // Push smallest two numbers to stack B
    for (int i = 0; i < 2; i++)
    {
        min = find_min(*a);
        pos = get_position(*a, min);
        
        // Get minimum to top using shortest path
        if (pos <= 2)  // Top half: rotate up
        {
            while (pos-- > 0)
                ra(a);
        }
        else  // Bottom half: rotate down
        {
            while (pos++ < 5 - i)
                rra(a);
        }
        pb(a, b);
    }

    // Sort remaining 3 numbers
    sort_three(a);

    // Push back both numbers
    pa(a, b);
    pa(a, b);
}

void sort_four(t_stack **a, t_stack **b)
{
    t_stack *min;
    int pos;

    if (!*a || stack_size(*a) != 4)
        return;

    // Push smallest number to stack B
    min = find_min(*a);
    pos = get_position(*a, min);
    
    // Get minimum to top using shortest path
    if (pos <= 1)  // Top half: rotate up
    {
        while (pos-- > 0)
            ra(a);
    }
    else  // Bottom half: rotate down
    {
        while (pos++ < 4)
            rra(a);
    }
    
    pb(a, b);
    sort_three(a);
    pa(a, b);
}

void sort_small(t_stack **a, t_stack **b)
{
    int size;

    size = stack_size(*a);
    if (size <= 1 || is_sorted(*a))
        return;
    else if (size == 2)
        sa(a);
    else if (size == 3)
        sort_three(a);
    else if (size == 4)
        sort_four(a, b);
    else if (size == 5)
        sort_five(a, b);
}
/*
This function:
    Gets the size of stack A
    Returns if stack is empty, has 1 element, or is already sorted
    For size 2: just needs a single swap if needed
    For sizes 3-5: routes to the appropriate specialized sorting function
*/