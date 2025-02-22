/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:18:58 by go-donne          #+#    #+#             */
/*   Updated: 2025/02/22 13:29:14 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void sort_three(t_stack **a)
{
    int first = (*a)->nbr;
    int second = (*a)->next->nbr;
    int third = (*a)->next->next->nbr;

    if (first > second && second < third && first < third)
        sa(a);  // Case: 2 1 3 -> 1 2 3
    else if (first > second && second > third)
    {
        sa(a);  // Case: 3 2 1 -> 2 3 1
        rra(a); // -> 1 2 3
    }
    // Add other cases...
}