#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../Libft/libft.h"

void insert_stack(t_list **stack, char **val);
int main(int ac, char **av);

void    Exit();
long	overflow_check(const char *str);
int 	check_over(long num, const char c, int minus);

void    check_overflow(char *val);
int     check_double_zero(char *val);
void    check_overlap(char **val);
void    check_digit(char *val);
int		ft_strcmp(const char *str, const char *str2);

int    param_check(char **av);

#endif