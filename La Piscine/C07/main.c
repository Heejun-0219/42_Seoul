/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 04:20:16 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/17 06:49:26 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
char	**ft_split(char *str, char *charset)
{
	int i = 0;
	int j;
	int count = 0;
//	int flag = 0;
	while (str[i])
	{
		j = 0;
		while (charset[j])
			if 
	}
	while (str[i])
	{
		j = 0;
		while (charset[j])
			if (charset[j++] == str[i])
				if (flag)
					count++;
		if (! flag) 

		++i;
	}
	j = 0;
	while (charset[j])
		if (str[i - 1] == charset[j++])
			count++;
	char **p = (char **)malloc((sizeof(char *)) * (count + 1));
	printf("%d \n", count);
	return (p);
}

int	main(void)
{
	char *s1;
	char *s2;
	char **words;
	s1 = "asdf2439#85723RETV#WYWER5w%^YW#$%6";
	s2 = "";
	words = ft_split(s1, s2);
	printf("address : %p\n", words);
	if (!*words) printf("(blank)\n");
	while (*words)
		printf("%s\n", *(words++));
	printf("\n");
	s1 = "asdf2439#85723RETV#WYWER5w%^YW#$%6";
	s2 = " ";
	words = ft_split(s1, s2);
	printf("address : %p\n", words);
	if (!*words) printf("(blank)\n");
	while (*words)
		printf("%s\n", *(words++));
	printf("\n");
	s1 = "";
	s2 = "";
	words = ft_split(s1, s2);
	printf("address : %p\n", words);
	if (!*words) printf("(blank)\n");
	while (*words)
		printf("%s\n", *(words++));
	printf("\n");
	s1 = "    ! asf as!adg asdf asf    asdf     ";
	s2 = " !";
	words = ft_split(s1, s2);
	printf("address : %p\n", words);
	if (!*words) printf("(blank)\n");
	while (*words)
		printf("%s\n", *(words++));
	printf("\n");
	s1 = " hi!my name!   is soon!hyung.";
	s2 = " ";
	words = ft_split(s1, s2);
	printf("address : %p\n", words);
	if (!*words) printf("(blank)\n");
	while (*words)
		printf("%s\n", *(words++));
	printf("\n");
	s1 = "                          ";
	s2 = " !";
	words = ft_split(s1, s2);
	printf("address : %p\n", words);
	if (!*words) printf("(blank)\n");
	while (*words)
		printf("%s\n", *(words++));
	printf("\n");
}
