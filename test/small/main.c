/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:02:13 by go-donne          #+#    #+#             */
/*   Updated: 2025/02/23 16:20:23 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

#include "test.h"

int main(void)
{
    t_test_stats stats = {0, 0, 0};
    
    test_all(&stats);
    print_final_stats(&stats);
    
    return (stats.failed > 0);
}
