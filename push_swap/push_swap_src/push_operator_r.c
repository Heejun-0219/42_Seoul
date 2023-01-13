#include "push_swap.h"

void    ra(t_list **a)
{
    t_list *last;
    t_list *first;

    if (!*a || !(*a)->next)
        return ;
    last = *a;
    first = *a;
    ft_lstlast(last)->next = last;
    *a = first->next;
    first->next = NULL;
    ft_putstr_fd("ra\n", 1);   
}

void    rb(t_list **b)
{
    t_list *last;
    t_list *first;

    if (!*b || !(*b)->next)
        return ;
    last = *b;
    first = *b;
    ft_lstlast(last)->next = last;
    *b = first->next;
    first->next = NULL;
    ft_putstr_fd("rb\n", 1);   
}

void    rr(t_list **a, t_list **b)
{
    t_list *last;
    t_list *first;

    if (!*a || !(*a)->next)
        return ;
    last = *a;
    first = *a;
    ft_lstlast(last)->next = last;
    *a = first->next;
    first->next = NULL;
    if (!*b || !(*b)->next)
        return ;
    last = *b;
    first = *b;
    ft_lstlast(last)->next = last;
    *b = first->next;
    first->next = NULL;
    ft_putstr_fd("rr\n", 1);  
}