/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:49:22 by go-donne          #+#    #+#             */
/*   Updated: 2025/02/22 13:49:25 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Helper to get values while maintaining norm length
static void get_three_values(t_stack *stack, int *a, int *b, int *c)
{
    *a = stack->nbr;
    *b = stack->next->nbr;
    *c = stack->next->next->nbr;
}

// Returns 1 if stack of 3 numbers is sorted, 0 otherwise
static int is_three_sorted(t_stack *stack)
{
    return (stack->nbr < stack->next->nbr && 
            stack->next->nbr < stack->next->next->nbr);
}

void sort_three(t_stack **a)
{
    int first;
    int second; 
    int third;

    if (!*a || !(*a)->next || !(*a)->next->next)
        return;
    get_three_values(*a, &first, &second, &third);
    
    // Already sorted
    if (first < second && second < third)
        return;
    // 2 1 3 -> 1 2 3
    else if (first > second && second < third && first < third)
        sa(a);
    // 3 1 2 -> 1 3 2 -> 1 2 3
    else if (first > second && second < third && first > third)
    {
        ra(a);
        sa(a);
    }
    // 2 3 1 -> 1 2 3
    else if (first < second && second > third && first > third)
        rra(a);
    // 3 2 1 -> 2 3 1 -> 1 2 3
    else if (first > second && second > third)
    {
        sa(a);
        rra(a);
    }
    // 1 3 2 -> 1 2 3
    else if (first < second && second > third && first < third)
        sa(a); // equivalent to: sa(a), ra(a), sa(a), rra(a)
}