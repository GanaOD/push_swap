/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:22:29 by go-donne          #+#    #+#             */
/*   Updated: 2025/02/22 14:38:02 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Push top element from src to dst
// "Private" core function - does the actual work
void push(t_stack **dst, t_stack **src)
{
    t_stack *temp;

    if (!*src)
        return;
    temp = stack_pop(src);
    stack_add_front(dst, temp);
}

// "Public" interface functions - use core function + print operation
void pa(t_stack **a, t_stack **b)
{
    push(a, b);
    write(1, "pa\n", 3);
}

void pb(t_stack **a, t_stack **b)
{
    push(b, a);
    write(1, "pb\n", 3);
}
