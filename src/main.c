/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:23:30 by go-donne          #+#    #+#             */
/*   Updated: 2025/02/23 16:52:58 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;
    
    if (ac < 2)
        return (0);
        
    a = parse_args(ac, av);
    if (!a)
    {
        write(2, "Error\n", 6);
        return (1);
    }
    
    b = NULL;
    sort_stack(&a, &b);
    free_stack(&a);
    free_stack(&b);
    return (0);
}