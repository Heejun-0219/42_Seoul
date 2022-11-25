/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 07:27:32 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/15 11:41:11 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_change(char *str, int i, int *flag)
{
	if (str[i] >= '0' && str[i] <= '9')
		*flag = 0;
	else if (str[i] >= 'a' && str[i] <= 'z')
	{
		if (*flag)
		{
			str[i] -= 32;
			*flag = 0;
		}
	}
	else if (str[i] >= 'A' && str[i] <= 'Z')
	{
		if (!(*flag))
			str[i] += 32;
		*flag = 0;
	}
	else
		*flag = 1;
}

char	*ft_strcapitalize(char *str)
{
	int	flag;
	int	i;

	i = -1;
	flag = 1;
	while (str[++i])
		ft_change(str, i, &flag);
	return (str);
}
