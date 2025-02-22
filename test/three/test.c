/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:02:23 by go-donne          #+#    #+#             */
/*   Updated: 2025/02/22 15:20:31 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void print_stack(t_stack *stack)
{
    while (stack)
    {
        printf("%ld ", stack->nbr);
        stack = stack->next;
    }
    printf("\n");
}

// Implementation of create_stack_three
t_stack *create_stack_three(int a, int b, int c)
{
    t_stack *stack;

    stack = NULL;
    stack_add_back(&stack, create_node(a));
    stack_add_back(&stack, create_node(b));
    stack_add_back(&stack, create_node(c));
    return (stack);
}

static int verify_sorted(t_stack *stack, int expected[], int size)
{
    int i;

    i = 0;
    while (stack && i < size)
    {
        if (stack->nbr != expected[i])
            return (0);
        stack = stack->next;
        i++;
    }
    return (i == size && !stack);
}

static void test_case(t_stack *stack, int expected[], 
                     int size, char *desc, t_test_stats *stats)
{
    printf("Test %d: %s\n", stats->total + 1, desc);
    printf("Before: ");
    print_stack(stack);
    
    sort_three(&stack);
    
    printf("After:  ");
    print_stack(stack);
    
    if (verify_sorted(stack, expected, size))
    {
        printf("✓ PASS\n");
        stats->passed++;
    }
    else
    {
        printf("✗ FAIL\n");
        stats->failed++;
    }
    stats->total++;
    printf("\n");
    
    free_stack(&stack);
}

void test(t_test_stats *stats)
{
    int expected[3] = {1, 2, 3};

    printf("\n=== Testing sort_three ===\n\n");

    // Test all permutations
    test_case(create_stack_three(1, 2, 3), expected, 3, "Already sorted", stats);
    test_case(create_stack_three(2, 1, 3), expected, 3, "Simple swap needed", stats);
    test_case(create_stack_three(2, 3, 1), expected, 3, "Reverse rotation needed", stats);
    test_case(create_stack_three(3, 1, 2), expected, 3, "Rotate and swap needed", stats);
    test_case(create_stack_three(3, 2, 1), expected, 3, "Reverse sorted", stats);
    test_case(create_stack_three(1, 3, 2), expected, 3, "Single swap at end", stats);

    // Edge cases
    test_case(NULL, expected, 0, "NULL stack", stats);
    test_case(create_node(1), expected, 1, "Single element", stats);

    printf("\nResults: %d/%d tests passed\n\n", stats->passed, stats->total);
}