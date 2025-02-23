#include "test.h"

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