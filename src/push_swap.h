typedef struct s_stack
{
    long          nbr;       // The actual number
    long          index;     // Used for optimization
    struct s_stack *next;    // Next node in stack
    struct s_stack *prev;    // Previous node in stack
}   t_stack;