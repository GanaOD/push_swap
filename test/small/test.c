/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:02:23 by go-donne          #+#    #+#             */
/*   Updated: 2025/02/23 16:32:24 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int ft_itoa_buf(char *buf, long n)
{
    char    tmp[20];
    int     i;
    int     len;
    int     neg;

    if (n == 0)
    {
        buf[0] = '0';
        return (1);
    }
    neg = (n < 0);
    i = 0;
    while (n)
    {
        tmp[i++] = '0' + (neg ? -(n % 10) : (n % 10));
        n /= 10;
    }
    if (neg)
        tmp[i++] = '-';
    len = i;
    while (i--)
        buf[len - 1 - i] = tmp[i];
    return (len);
}

void print_stack(t_stack *stack)
{
    char buf[20];
    int len;

    // Start on fresh line
    write(1, "\n", 1);
    while (stack)
    {
        len = ft_itoa_buf(buf, stack->nbr);
        write(1, buf, len);
        write(1, " ", 1);
        stack = stack->next;
    }
    write(1, "\n", 1);
}

void print_test_header(const char *title)
{
    write(1, "\n=== Testing ", 12);
    write(1, title, strlen(title));
    write(1, " ===\n\n", 7);
}

void print_test_case(int test_num, const char *desc)
{
    char buf[20];
    int len;

    write(1, "Test ", 5);
    len = snprintf(buf, sizeof(buf), "%d", test_num);
    write(1, buf, len);
    write(1, ": ", 2);
    write(1, desc, strlen(desc));
    write(1, "\n", 1);
}

void print_result(int passed)
{
    if (passed)
        write(1, "✓ PASS\n", 8);
    else
        write(1, "✗ FAIL\n", 8);
    write(1, "\n", 1);
}

void print_final_stats(t_test_stats *stats)
{
    char buf[100];
    int len;

    write(1, "\nFinal Results: ", 15);
    len = snprintf(buf, sizeof(buf), "%d/%d tests passed\n\n", 
                  stats->passed, stats->total);
    write(1, buf, len);
}

static void test_case(t_stack **a, t_stack **b, int expected[], 
                     int size, char *desc, t_test_stats *stats)
{
    write(1, "\nTest ", 6);
    char num = '0' + (stats->total + 1);
    write(1, &num, 1);
    write(1, ": ", 2);
    write(1, desc, strlen(desc));
    write(1, "\n", 1);
    
    write(1, "Before:", 7);
    print_stack(*a);
    
    sort_small(a, b);
    
    write(1, "After:", 6);
    print_stack(*a);
    
    write(1, "\n", 1);
    if (verify_sorted(*a, expected, size))
    {
        write(1, "✓ PASS\n", 8);
        stats->passed++;
    }
    else
    {
        write(1, "✗ FAIL\n", 8);
        stats->failed++;
    }
    stats->total++;
    write(1, "\n", 1);
    
    free_stack(a);
    free_stack(b);
}

void test_three(t_test_stats *stats)
{
    t_stack *a;
    t_stack *b;
    int arr[3];
    int expected[3] = {1, 2, 3};

    print_test_header("3 Numbers");

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

    // Reverse rotation needed
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

    print_test_header("4 Numbers");

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

    print_test_header("5 Numbers");

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