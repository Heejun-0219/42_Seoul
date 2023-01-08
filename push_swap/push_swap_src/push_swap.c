#include <stdio.h>
#include "push_swap.h"

void    Exit() // 문자열 free하고 종료하기 
{
    ft_putstr_fd("Error\n", 1);
    exit(1);
}

int		ft_strcmp(const char *str, const char *str2)
{
	unsigned char *s1;
	unsigned char *s2;

	s1 = (unsigned char *)str;
	s2 = (unsigned char *)str2;
	while (*s1 == *s2 && *s1 && s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int insert_stack(int *stack, char **val, int size)
{
    int i;

    i = 0;
    while (i++ < size)
    {
        printf("%s", val[i]);
        stack[i - 1] = ft_atoi(val[i]);
    }
    return (0);
}


void check_digit(char *val)
{
    int i;

    i = 0;
    if (val[i] == '-')
        i++;
    while (val[i])
    {
        if(!ft_isdigit(val[i]))
            Exit();
        i++;
    }
}

void check_overlap(char **val)
{
    char    **tmp;

    tmp = val;
    while (*(++tmp))
    {
        if (!ft_strcmp(*val, *tmp))
            Exit();
    }
}

int is_sign(int c)
{
    return (c == '+' || c == '-');
}

int check_double_zero(char *val)
{
    int i;

    i = 0;
    if (is_sign(val[i]))
        i++;
    while (val[i] && val[i] == '0')
        i++;
    if (val[i] != '\0')
        return (0);
    return (1);
}

void check_overflow(char *val)
{
    const long num = overflow_check(val);
    if (num > INT_MAX || num < INT_MIN)
        Exit();
}

void    param_check(char **av)
{
    int i;
    int dou_zero;

    dou_zero = 0;
    i = 1;
    while (av[i])
    {
        check_digit(av[i]);
        check_overlap(&av[i]);
        dou_zero += check_double_zero(av[i]);
        check_overflow(av[i]);
        i++;

        if (dou_zero > 1)
            Exit();
    }
}

int main(int ac, char **av)
{
    int     *a;
    char    **str;
    //int     *b;

    if (ac < 2)
        Exit();
    //매개변수 문자열 하나 or 문자열 갯수만큼 확인
    if (ac == 2)
        str = ft_split(av[1], ' ');
    else
        str = av;
        // 매개변수 문자열 갯수만큼 입력
    //매개변수 ft_isdigit, double, overflow 확인 => Error
    param_check(str);

    a = (int *)malloc(sizeof(int) * ac - 1);
    if(insert_stack(a, av, ac - 1) == -1) // 에러반응 함수 안으로 exit 
    {
        write(1, "Error\n", 6);
        return (-1);
    }

    while (ac--)
    {
        printf(" %d", *(a++));
    }
    
    return (0);
}