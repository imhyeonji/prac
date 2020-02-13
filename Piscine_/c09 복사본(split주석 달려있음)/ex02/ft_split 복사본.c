/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 22:15:26 by hyim              #+#    #+#             */
/*   Updated: 2020/02/11 19:10:48 by hyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_sep(char c, char *charset)
{
	int i;

	i = 0;
	if (c == '\0')
		return (1);
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_count_words(char *str, char *charset)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (!(ft_is_sep(str[i], charset)) && ft_is_sep(str[i + 1], charset))
			count++;
		i++;
	}
	return (count);
}

void	ft_put_str(char *dest, char *src, char *charset)
{
	int	i;

	i = 0;
	{
		while (ft_is_sep(src[i], charset) == 0)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
}

void	ft_put_arr(char **arr, char *str, char *charset)
{
	int		i;
	int		j;
	int		index;

	index = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_is_sep(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (ft_is_sep(str[i + j], charset) == 0)
				j++;
			arr[index] = (char*)malloc(sizeof(char) * (j + 1));
			ft_put_str(arr[index], str + i, charset);
			i = i + j;
			index++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		len;

	len = ft_count_words(str, charset);
	arr = (char**)malloc(sizeof(char*) * (len + 1));
	arr[len] = 0;
	ft_put_arr(arr, str, charset);
	return (arr);
}

#include <stdio.h>

int		main(int argc, char **argv)
{
	int		index;
	char	**split;

	printf("=====YOUR ANSWER=====\n");
	split = ft_split("kabck++jkingzlim!m", "kz!");
	index = 0;
	printf("tab start\n");
	while (split[index])
	{
		printf("tab[%d]: $%s$\n", index, split[index]);
		index++;
	}
	printf("tab end\n");
}

