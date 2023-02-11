/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utilts_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 09:39:17 by heejunki          #+#    #+#             */
/*   Updated: 2023/02/11 09:39:25 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_distance(int index, int size)
{
    if (index > size / 2)
        index -= size;
    return (index);
}

int ra_rra_move_to_a(int distance, int sector, t_list **a, t_list **b)
{
    while (distance > 0 && sector > 0)
    {
        rr(a, b);
        a--;
        b--;
    }
    while (distance < 0 && sector < 0)
    {
        rrr(a, b);
        a++;
        b++;
    }
    while (sector > 0)
    {
        ra(a);
        sector--;
    }
    while (sector < 0)
    {
        rra(a);
        sector++;
    }
    return (distance);    
}