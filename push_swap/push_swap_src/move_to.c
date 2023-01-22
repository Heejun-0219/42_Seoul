#include "push_swap.h"
#include <stdio.h>

int find_pos(t_list *a, int *lis, int max)
{
    int pos;
    int i;
    int flag;

    pos = 0;
    i = 0;
    while (a != NULL)
    {
        i = 0;
        flag = 0;
        while (i < max)
        {
            if (a->content == lis[i])
                flag = 1;
            i++;
        }
        if (!flag)
            return (pos);
        a = a->next;
        pos++;
    }
    return (-1);
}

void    move_to_b(t_list **a, t_list **b, int *lis, int max)
{
    int a_size;
    int count_ra;

    a_size = ft_lstsize(*a);
    while (a_size > max)
    {
        count_ra = find_pos(*a, lis, max);
        if (count_ra == -1)
            eexit();
        while (count_ra-- > 0)
            ra(a);
        pb(a, b);
        a_size = ft_lstsize(*a);
    }    
}

void    move_to_a(t_list **a, t_list **b)
{

    while (*b != NULL)
    {
        /* code */
    }
    
}