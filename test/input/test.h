#ifndef TEST_H
# define TEST_H

#include "../../inc/push_swap.h"
#include <stdio.h>
#include <limits.h>
#include "libft.h"

typedef struct s_test_stats {
    int passed;
    int failed;
    int total;
} t_test_stats;

void test_case(int ac, char **av, int expected_valid, const char *desc, t_test_stats *stats);

// Test functions
void test_valid_inputs(t_test_stats *stats);
void test_invalid_numbers(t_test_stats *stats);
void test_duplicates(t_test_stats *stats);
void test_edge_cases(t_test_stats *stats);
void test_all(t_test_stats *stats);

#endif