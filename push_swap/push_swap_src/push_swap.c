#include <stdio.h>
#include "push_swap.h"

void    Exit()
{
    ft_putstr_fd("Error", 1);
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

void check_overflow(char *val)
{
    (void)val;
}

void    param_check(char **av)
{
    int i;

    i = 1;
    while (av[i])
    {
        check_digit(av[i]);
        check_overlap(&av[i]);
        check_overflow(av[i]);
        i++;
    }
}

int main(int ac, char **av)
{
    int size = ac - 1;
    int     *a;
    char    **str;
    //int     *b;

    //매개변수 문자열 하나 or 문자열 갯수만큼 확인
    if (ac == 2)
        str = ft_split(av[1], ' ');
    else
        // 매개변수 문자열 갯수만큼 입력
        
    (void)str;
    //매개변수 ft_isdigit, double, overflow 확인 => Error
    param_check(av);

    printf("%d ", size);
    a = (int *)malloc(sizeof(int) * size);
    if(insert_stack(a, av, size) == -1) // 에러반응 함수 안으로 exit 
    {
        write(1, "Error\n", 6);
        return (-1);
    }

    while (size-- > 0)
    {
        printf(" %d", *(a++));
    }
    
    return (0);
}