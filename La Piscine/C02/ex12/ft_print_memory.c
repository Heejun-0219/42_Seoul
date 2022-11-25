/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:30:07 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/11 06:36:38 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print_addr(unsigned long long addr, int range)
{
	unsigned long long	tmp;
	int					i;
	unsigned char		arr[16];
	char				*hex;

	tmp = addr + range;
	hex = "0123456789abcdef";
	i = 15;
	while (i >= 0 && tmp / 16)
	{
		arr[i--] = hex[tmp % 16];
		tmp /= 16;
	}
	arr[i--] = hex[tmp];
	while (i >= 0)
	{
		arr[i--] = '0';
	}
	i = 0;
	while (i <= 15)
	{
		write(1, &arr[i++], 1);
	}
	write(1, ": ", 2);
}

void	print_hex(unsigned char *str, int range)
{
	int		i;
	char	*hex;

	hex = "0123456789abcdef";
	i = range;
	while (i < range + 16)
	{
		if (str[i])
		{
			write(1, &(hex[str[i] / 16]), 1);
			write(1, &(hex[str[i] % 16]), 1);
			write(1, &(hex[str[i + 1] / 16]), 1);
			write(1, &(hex[str[i + 1] % 16]), 1);
		}
		else
			write(1, "    ", 4);
		write(1, " ", 1);
		i += 2;
	}
}

void	print_str(unsigned char *str, int index)
{
	int	i;

	i = index;
	while (str[i] && i < index + 16)
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		else
			write(1, ".", 1);
		++i;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	index;

	index = 1;
	while (index < size)
	{
		if (index % 16 == 0)
		{
			print_addr((unsigned long long) addr, index - 16);
			print_hex((unsigned char *) addr, index - 16);
			print_str((unsigned char *) addr, index - 16);
			++index;
		}
		else if (index == size - 1)
		{
			print_addr((unsigned long long) addr, index - (index % 16));
			print_hex((unsigned char *) addr, index - (index % 16));
			print_str((unsigned char *) addr, index - (index % 16));
			++index;
		}
		else
		{
			++index;
		}
	}
	return (addr);
}
