/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:02:23 by go-donne          #+#    #+#             */
/*   Updated: 2025/02/22 16:00:29 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void print_stack(t_stack *stack)
{
    while (stack)
    {
        printf("%ld ", stack->nbr);
        stack = stack->next;
    }
    printf("\n");
}

t_stack *create_stack_n(int arr[], int size)
{
    t_stack *stack;
    int i;

    stack = NULL;
    i = 0;
    while (i < size)
    {
        stack_add_back(&stack, create_node(arr[i]));
        i++;
    }
    return (stack);
}

int verify_sorted(t_stack *stack, int expected[], int size)
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

static void test_case(t_stack **a, t_stack **b, int expected[], 
                     int size, char *desc, t_test_stats *stats)
{
    printf("Test %d: %s\n", stats->total + 1, desc);
    printf("Before: ");
    print_stack(*a);
    
    sort_small(a, b);
    
    printf("After:  ");
    print_stack(*a);
    
    if (verify_sorted(*a, expected, size))
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
    
    free_stack(a);
    free_stack(b);
}

void test_three(t_test_stats *stats)
{
    t_stack *a;
    t_stack *b;
    int arr[3];
    int expected[3] = {1, 2, 3};

    printf("\n=== Testing 3 Numbers ===\n\n");

    // Already sorted
    arr[0] = 1; arr[1] = 2; arr[2] = 3;
    a = create_stack_n(arr, 3);
    b = NULL;
    test_case(&a, &b, expected, 3, "Already sorted", stats);

    // Simple swap needed
    arr[0] = 2; arr[1] = 1; arr[2] = 3;
    a = create_stack_n(arr, 3);
    b = NULL;
    test_case(&a, &b, expected, 3, "Simple swap needed", stats);

    // Other permutations...
    arr[0] = 2; arr[1] = 3; arr[2] = 1;
    a = create_stack_n(arr, 3);
    b = NULL;
    test_case(&a, &b, expected, 3, "Reverse rotation needed", stats);
}

void test_four(t_test_stats *stats)
{
    t_stack *a;
    t_stack *b;
    int arr[4];
    int expected[4] = {1, 2, 3, 4};

    printf("\n=== Testing 4 Numbers ===\n\n");

    // Already sorted
    arr[0] = 1; arr[1] = 2; arr[2] = 3; arr[3] = 4;
    a = create_stack_n(arr, 4);
    b = NULL;
    test_case(&a, &b, expected, 4, "Already sorted", stats);

    // Reverse sorted
    arr[0] = 4; arr[1] = 3; arr[2] = 2; arr[3] = 1;
    a = create_stack_n(arr, 4);
    b = NULL;
    test_case(&a, &b, expected, 4, "Reverse sorted", stats);

    // Minimum in middle
    arr[0] = 3; arr[1] = 1; arr[2] = 4; arr[3] = 2;
    a = create_stack_n(arr, 4);
    b = NULL;
    test_case(&a, &b, expected, 4, "Minimum in middle", stats);
}

void test_five(t_test_stats *stats)
{
    t_stack *a;
    t_stack *b;
    int arr[5];
    int expected[5] = {1, 2, 3, 4, 5};

    printf("\n=== Testing 5 Numbers ===\n\n");

    // Already sorted
    arr[0] = 1; arr[1] = 2; arr[2] = 3; arr[3] = 4; arr[4] = 5;
    a = create_stack_n(arr, 5);
    b = NULL;
    test_case(&a, &b, expected, 5, "Already sorted", stats);

    // Reverse sorted
    arr[0] = 5; arr[1] = 4; arr[2] = 3; arr[3] = 2; arr[4] = 1;
    a = create_stack_n(arr, 5);
    b = NULL;
    test_case(&a, &b, expected, 5, "Reverse sorted", stats);

    // Random order
    arr[0] = 3; arr[1] = 5; arr[2] = 1; arr[3] = 4; arr[4] = 2;
    a = create_stack_n(arr, 5);
    b = NULL;
    test_case(&a, &b, expected, 5, "Random order", stats);
}

void test_all(t_test_stats *stats)
{
    test_three(stats);
    test_four(stats);
    test_five(stats);
}