/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:57:59 by go-donne          #+#    #+#             */
/*   Updated: 2025/02/22 15:20:32 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "../inc/push_swap.h"
# include <stdio.h>

typedef struct s_test_stats {
    int passed;
    int failed;
    int total;
} t_test_stats;

// Helper function declaration
t_stack *create_stack_three(int a, int b, int c);

// Only one declaration of test
void test(t_test_stats *stats);

#endif
