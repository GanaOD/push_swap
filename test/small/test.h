/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:57:59 by go-donne          #+#    #+#             */
/*   Updated: 2025/02/22 15:54:08 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "../../inc/push_swap.h"
# include <stdio.h>

typedef struct s_test_stats {
    int passed;
    int failed;
    int total;
} t_test_stats;

// Helper functions
t_stack *create_stack_n(int arr[], int size);
void    print_stack(t_stack *stack);
int     verify_sorted(t_stack *stack, int expected[], int size);

// Test functions
void test_three(t_test_stats *stats);
void test_four(t_test_stats *stats);
void test_five(t_test_stats *stats);
void test_all(t_test_stats *stats);

#endif
