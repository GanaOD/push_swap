#include "test.h"

int main(void)
{
    t_test_stats stats = {0, 0, 0};
    
    test_all(&stats);
    printf("\nFinal Results: %d/%d tests passed\n\n", 
           stats.passed, stats.total);
    
    return (stats.failed > 0);
}