/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 09:35:12 by heejunki          #+#    #+#             */
/*   Updated: 2023/02/11 09:36:21 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *list_data_copy(t_list *a, int size)
{
    int *data;
    int i;

    data = (int *)malloc(sizeof(int) * size);
    if (!data)
        exit(-1);
    i = 0;
    while (a != NULL)
    {
        data[i++] = a->content;
        a = a->next;
    }
    return (data);
}

int *return_lis(int *data, int *step, int size, int max)
{
    int *lis;
    int i;

    lis = (int *)malloc(sizeof(int) * max);
    if (!lis)
        exit(-1);
    i = size - 1;
    while (i >= 0)
    {
        if (step[i] == max)
        {
            lis[max - 1] = data[i];
            max--;
        }
        i--;
    }
    free(step);
    return (lis);
}

void    find_step(int *data, int *step, int size)
{
    int i;
    int j;

    i = 1;
    while (i < size)
    {
        j = 0;
        while (j < i)
        {
            if(data[i] > data[j] && step[i] < step[j] + 1)
                step[i] = step[j] + 1;
            j++;
        }
        i++;
    }
}

int *count_lis(int *data, int size, int *max)
{
    int *step;
    int i;

    step = (int *)malloc(sizeof(int) * size);
    if (!step)
        exit(-1);
    i = 0;
    while (i < size)
        step[i++] = 1;
    find_step(data, step, size);
    i = 0;
    while (i < size)
        if (*max < step[i++])
            *max = step[i - 1];
    return (return_lis(data, step, size, *max));
}
