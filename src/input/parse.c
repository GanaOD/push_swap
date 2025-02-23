/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:47:06 by go-donne          #+#    #+#             */
/*   Updated: 2025/02/23 17:28:30 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void free_split(char **strs)
{
    int i;
    
    i = 0;
    while (strs[i])
        free(strs[i++]);
    free(strs);
}

static int has_duplicate(t_stack *stack, long num)
{
    while (stack)
    {
        if (stack->nbr == num)
            return (1);
        stack = stack->next;
    }
    return (0);
}

static int is_valid_int(const char *str, long *num)
{
    int sign;
    long result;
    
    result = 0;
    sign = (*str == '-') ? -1 : 1;
    if (*str == '-' || *str == '+')
        str++;
    if (!*str)
        return (0);
    while (*str)
    {
        if (*str < '0' || *str > '9')
            return (0);
        result = result * 10 + (*str++ - '0');
    }
    result *= sign;
    if (result > INT_MAX || result < INT_MIN)
        return (0);
    *num = result;
    return (1);
}

t_stack *parse_args(int ac, char **av)
{
    t_stack *stack;
    char    **nums;
    long    num;
    int     i;
    int     count;
    
    if (ac < 2)
        return (NULL);
    stack = NULL;
    nums = (ac == 2) ? ft_split(av[1], ' ') : av + 1;
    count = (ac == 2) ? 0 : ac - 1;
    i = 0;
    while (nums[i] && (ac == 2 || i < count))
    {
        if (!is_valid_int(nums[i], &num) || has_duplicate(stack, num))
        {
            free_stack(&stack);
            if (ac == 2)
                free_split(nums);
            return (NULL);
        }
        stack_add_back(&stack, create_node(num));
        i++;
    }
    if (ac == 2)
        free_split(nums);
    return (stack);
}