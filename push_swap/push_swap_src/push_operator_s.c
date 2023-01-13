#include "push_swap.h"

void    sa(t_list **a)
{
    t_list	*top;
	t_list	*second;

	top = *a;
	second = top->next;
	*a = second;
	top->next = second->next;
	second->next = top;
    ft_putstr_fd("sa\n", 1);
}

void    sb(t_list **b)
{
    t_list	*top;
	t_list	*second;

	top = *b;
	second = top->next;
	*b = second;
	top->next = second->next;
	second->next = top;
    ft_putstr_fd("sb\n", 1);
}

void    ss(t_list **a, t_list **b)
{
    t_list	*top;
	t_list	*second;

	top = *a;
	second = top->next;
	*a = second;
	top->next = second->next;
	second->next = top;
    top = NULL;
    second = NULL;
    top = *b;
	second = top->next;
	*b = second;
	top->next = second->next;
	second->next = top;
    ft_putstr_fd("ss\n", 1);
}
