/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:49:22 by go-donne          #+#    #+#             */
/*   Updated: 2025/02/22 16:26:07 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Helper to get values while maintaining norm length
static void get_three_values(t_stack *stack, int *a, int *b, int *c)
{
    *a = stack->nbr;
    *b = stack->next->nbr;
    *c = stack->next->next->nbr;
}

// // Returns 1 if stack of 3 numbers is sorted, 0 otherwise
// static int is_three_sorted(t_stack *stack)
// {
//     return (stack->nbr < stack->next->nbr && 
//             stack->next->nbr < stack->next->next->nbr);
// }

void sort_three(t_stack **a)
{
    int first;
    int second; 
    int third;

    if (!*a || !(*a)->next || !(*a)->next->next)
        return;
    get_three_values(*a, &first, &second, &third);
    
    if (first < second && second < third)
        return;
    else if (first > second && second < third && first < third)
        sa(a);
    else if (first > second && second < third && first > third)
        (rra(a), sa(a), rra(a), rra(a), sa(a));
    else if (first < second && second > third && first > third)
        rra(a);
    else if (first > second && second > third)
        (sa(a), rra(a));
    else if (first < second && second > third && first < third)
        (sa(a), ra(a));
}

void sort_four(t_stack **a, t_stack **b)
{
    t_stack *min;
    int pos;

    if (!*a || stack_size(*a) != 4)
        return;

    // Find minimum and its position
    min = find_min(*a);
    pos = get_position(*a, min);

    // Move minimum to top based on its position
    if (pos == 1)
        sa(a);
    else if (pos == 2)
        (ra(a), ra(a));
    else if (pos == 3)
        rra(a);

    // Push minimum to B, sort remaining 3, push back
    pb(a, b);
    sort_three(a);
    pa(a, b);
}

void sort_five(t_stack **a, t_stack **b)
{
    t_stack *min;
    int pos;

    if (!*a || stack_size(*a) != 5)
        return;

    // Push smallest two numbers to B
    for (int i = 0; i < 2; i++)
    {
        min = find_min(*a);
        pos = get_position(*a, min);

        // Move minimum to top - each operation separate
        if (pos == 1)
            sa(a);
        else if (pos == 2)
        {
            ra(a);
            ra(a);
        }
        else if (pos == 3)
        {
            rra(a);
            rra(a);
        }
        else if (pos == 4)
            rra(a);
        pb(a, b);
    }

    // Sort remaining 3 in A
    sort_three(a);

    // Push back from B and ensure order is maintained
    while (*b)
    {
        pa(a, b);
        if ((*a)->nbr > (*a)->next->nbr)
            sa(a);
    }
}

// Main sorting function for small stacks
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