/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:02:13 by go-donne          #+#    #+#             */
/*   Updated: 2025/02/22 16:00:28 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int main(void)
{
    t_test_stats stats = {0, 0, 0};
    
    test_all(&stats);
    printf("\nFinal Results: %d/%d tests passed\n\n", 
           stats.passed, stats.total);
    
    return (stats.failed > 0);
}
