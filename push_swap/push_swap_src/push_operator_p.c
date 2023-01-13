#include "push_swap.h"

void    pa(t_list **a, t_list **b)
{
    t_list *tmp;

    if (!*b)
        return ;
    tmp = *a;
    *a = (*a)->next;
    tmp->next = *b;
    *b = tmp;
    ft_putstr_fd("pa\n", 1);
}

void    pb(t_list **a, t_list **b)
{
    t_list *tmp;

    if (!*a)
        return ;
    tmp = *b;
    *b = (*b)->next;
    tmp->next = *a;
    *a = tmp;
    ft_putstr_fd("pb\n", 1); 
}