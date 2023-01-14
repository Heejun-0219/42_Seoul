#include <stdio.h>
#include "push_swap.h"

void insert_stack(t_list **stack, char **val)
{
    int i;
    t_list  *tmp;

    i = 0;
    tmp = NULL;
    while (val[i])
    {
        tmp = ft_lstnew(ft_atoi(val[i]));
        ft_lstadd_back(stack, tmp);
        i++;
    }
}

// printf value
void ft_lstprint(t_list *val){
    while (val)
    {
        printf("%d ", val->content);
        val = val->next;
    }
    printf("\n\n");
}

int main(int ac, char **av)
{
    t_list     *a;
    t_list     *b;
    int     size;
    char    **parameter;

    if (ac < 2)
        Exit();
    //매개변수 문자열 하나 or 문자열 갯수만큼 확인
    if (ac == 2)
        parameter = ft_split(av[1], ' ');
    else
        parameter = ++av;
        // 매개변수 문자열 갯수만큼 입력
    //매개변수 ft_isdigit, double, overflow 확인 => Error
    size = param_check(parameter);

    a = NULL;
    b = NULL;
    insert_stack(&a, parameter);// 에러반응 함수 안으로 exit 

    (void)size;
    (void)*b;
    ft_lstprint(a);

    sa(&a);
    ft_lstprint(a);

    pb(&a, &b);
    pb(&a, &b);
    ft_lstprint(a);
    ft_lstprint(b);

    sb(&b);
    ft_lstprint(b);

    ss(&a, &b);
    ft_lstprint(a);
    ft_lstprint(b); 

    pa(&a, &b);
    ft_lstprint(a);
    ft_lstprint(b); 
    pb(&a, &b);

    ra(&a);
    rb(&b);
    ft_lstprint(a);
    ft_lstprint(b); 

    rr(&a, &b);
    ft_lstprint(a);
    ft_lstprint(b); 

    rra(&a);
    rrb(&b);
    ft_lstprint(a);
    ft_lstprint(b); 

    rrr(&a, &b);
    ft_lstprint(a);
    ft_lstprint(b); 
    return (0);
}