#include "push_swap.h"

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

int check_double_zero(char *val)
{
    int i;

    i = 0;
    if (val[i] == '+' || val[i] == '-')
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
