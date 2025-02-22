/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:49:22 by go-donne          #+#    #+#             */
/*   Updated: 2025/02/22 15:26:44 by go-donne         ###   ########.fr       */
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
