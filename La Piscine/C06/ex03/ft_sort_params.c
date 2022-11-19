/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:42:15 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/15 21:48:19 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	str_wr3(char c)
{
	write(1, &c, 1);
}

void	str_ln3(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		str_wr3(str[i]);
		i++;
	}
}

int	str_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	if (s1[i] == s2[i])
		return (0);
	else
		return (s2[i] - s2[i]);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		k;
	char	*temp;

	i = 1;
	while (argc > 1 && i < argc)
	{
		k = i + 1;
		while (k < argc)
		{
			if (str_cmp(argv[i], argv[k]) > 0)
			{
				temp = argv[i];
				argv[i] = argv[k];
				argv[k] = temp;
			}
			k++;
		}
		str_ln3(argv[i]);
		str_wr3('\n');
		i++;
	}
	return (0);
}
