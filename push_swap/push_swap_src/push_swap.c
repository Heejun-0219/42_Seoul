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
}

int main(int ac, char **av)
{
    t_list     *a;
    t_list     *b = NULL;
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
    insert_stack(&a, parameter);// 에러반응 함수 안으로 exit 

    (void)size;
    (void)*b;
    ft_lstprint(a);
    
    return (0);
}