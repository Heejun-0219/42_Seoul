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

int    param_check(char **av)
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
    return (i);
}