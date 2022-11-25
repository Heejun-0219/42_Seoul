/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:02:06 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/20 12:35:27 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

int		op_plus(int a, int b);
int		op_minus(int a, int b);
int		op_multi(int a, int b);
int		op_div(int a, int b);
int		op_mod(int a, int b);

void	ft_putnbr(int nb);
int		ft_c_strcmp(char c, char *s2);
int		ft_atoi(char *str);
void	cal(int a, char *op, int b);

#endif
