#include "test.h"

void test_case(int ac, char **av, int expected_valid, const char *desc, t_test_stats *stats)
{
    t_stack *stack;
    
    printf("Test %d: %s\n", stats->total + 1, desc);
    printf("Input: ");
    for (int i = 1; i < ac; i++)
        printf("%s ", av[i]);
    printf("\n");
    
    stack = parse_args(ac, av);
    printf("Stack returned: %s\n", stack ? "non-NULL" : "NULL");
    
    // Print the stack contents if not NULL
    if (stack)
    {
        printf("Stack contents: ");
        t_stack *current = stack;
        while (current)
        {
            printf("%ld ", current->nbr);
            current = current->next;
        }
        printf("\n");
    }
    
    if ((stack != NULL) == expected_valid)
    {
        printf("✓ PASS\n");
        stats->passed++;
    }
    else
    {
        printf("✗ FAIL (expected %s, got %s)\n", 
               expected_valid ? "valid" : "invalid",
               stack ? "valid" : "invalid");
        stats->failed++;
    }
    stats->total++;
    printf("\n");
    
    if (stack)
        free_stack(&stack);
}

void test_duplicates(t_test_stats *stats)
{
    printf("\n=== Testing Duplicates ===\n\n");

    // Simple duplicate
    char *av1[] = {"./push_swap", "1", "2", "2", "3"};
    test_case(5, av1, 0, "Simple duplicate", stats);
    
    // Duplicate in quoted string
    char *av2[] = {"./push_swap", "1 2 2 3"};
    test_case(2, av2, 0, "Duplicate in quoted string", stats);
    
    // Duplicate at edges
    char *av3[] = {"./push_swap", "1", "2", "3", "1"};
    test_case(5, av3, 0, "Duplicate at edges", stats);
}

void test_edge_cases(t_test_stats *stats)
{
    printf("\n=== Testing Edge Cases ===\n\n");

    // Empty string
    char *av1[] = {"./push_swap", ""};
    test_case(2, av1, 0, "Empty string", stats);
    
    // Only spaces
    char *av2[] = {"./push_swap", "   "};
    test_case(2, av2, 0, "Only spaces", stats);
    
    // Signs without numbers
    char *av3[] = {"./push_swap", "+"};
    test_case(2, av3, 0, "Plus sign alone", stats);
    
    char *av4[] = {"./push_swap", "-"};
    test_case(2, av4, 0, "Minus sign alone", stats);
}

void test_valid_inputs(t_test_stats *stats)
{
    printf("\n=== Testing Valid Inputs ===\n\n");

    // Simple positive numbers
    char *av1[] = {"./push_swap", "1", "2", "3"};
    printf("Testing av1 with ac=4\n");  // Debug
    test_case(4, av1, 1, "Simple positive numbers", stats);
    
    // Mixed positive and negative
    char *av2[] = {"./push_swap", "-1", "5", "-2", "4"};
    printf("Testing av2 with ac=5\n");  // Debug
    test_case(5, av2, 1, "Mixed positive and negative", stats);
    
    // Single quoted string
    char *av3[] = {"./push_swap", "1 2 3"};
    printf("Testing av3 with ac=2\n");  // Debug
    test_case(2, av3, 1, "Single quoted string", stats);
}

void test_invalid_numbers(t_test_stats *stats)
{
    printf("\n=== Testing Invalid Numbers ===\n\n");

    // Non-numeric input
    char *av1[] = {"./push_swap", "1", "abc", "3"};
    test_case(4, av1, 0, "Non-numeric input", stats);
    
    // Too large for INT
    char *av2[] = {"./push_swap", "2147483648"};
    test_case(2, av2, 0, "Number > INT_MAX", stats);
    
    // Too small for INT
    char *av3[] = {"./push_swap", "-2147483649"};
    test_case(2, av3, 0, "Number < INT_MIN", stats);
}

// ... similar functions for test_duplicates() and test_edge_cases()

void test_all(t_test_stats *stats)
{
    test_valid_inputs(stats);
    test_invalid_numbers(stats);
    test_duplicates(stats);
    test_edge_cases(stats);
}