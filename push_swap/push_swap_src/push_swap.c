#include <stdio.h>
#include "push_swap.h"

void insert_stack(int *stack, char **val)
{
    int i;

    i = 0;
    while (val[i])
    {
        stack[i] = ft_atoi(val[i]);
        i++;
    }
}

int main(int ac, char **av)
{
    int     *a;
    int     size;
    char    **str;
    //int     *b;

    if (ac < 2)
        Exit();
    //매개변수 문자열 하나 or 문자열 갯수만큼 확인
    if (ac == 2)
        str = ft_split(av[1], ' ');
    else
        str = ++av;
        // 매개변수 문자열 갯수만큼 입력
    //매개변수 ft_isdigit, double, overflow 확인 => Error
    size = param_check(str);

    a = (int *)malloc(sizeof(int) * size);
    printf("%d", size);
    insert_stack(a, str);// 에러반응 함수 안으로 exit 

    while (*a)
    {
        printf(" %d", *(a++));
    }
    
    return (0);
}