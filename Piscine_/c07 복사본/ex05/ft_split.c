/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:53:50 by hyim              #+#    #+#             */
/*   Updated: 2020/02/06 15:05:56 by hyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while(*str)
		i++;
	return (i);
}

int	ft_find_sep(char *str, char *charset, int index)
{
	int i;

	i = 0;
	while (*str)
	{
		if (charset[index] == str[i])
			return (i);
		i++;
	}
	return (0);
}

char **ft_split(char *str, char *charset)
{
	char **temp;
	int str_size;
	int sep_size;
	int i;
	int j;

	str_size = ft_strlen(str);
	sep_size = ft_strlen(charset);
	temp = malloc(sizeof(char*) * (str_size - sep_size) + 1);
	i = 0;
	while (i < sep_size)
	{
		j = 0;
		if (ft_find_sep(str, charset, i))
		{
			while (j < (ft_find_sep(str, charset, i)))
			{
				temp[i][j] = str[j];
				j++;
			}
		}
		i++;
	}
	return (temp);
}

int	main(void)
{
	char **a = ft_split("aaAbbBccCddDeeEhhHkkK", "ABCDEHK");

	int i;

	i = 0;
	while (1)
	{
		if (a[i] == '\0')
			break;
		printf("%s", a[i]);
		i++;
	}
}
