/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:11:18 by hyim              #+#    #+#             */
/*   Updated: 2020/01/28 12:00:57 by hyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_cap(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_low(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_num(int n)
{
	return (n >= '0' && n <= '9');
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 || !(ft_cap(str[i-1]) || ft_low(str[i-1]) || ft_num(str[i-1])))
		{
			if(ft_low(str[i]))
				str[i] = str[i] - 32;
			else if(ft_cap(str[i]))
				str[i] = str[i] + 32;	
		}
		i++;
	}
	return (str);
}

int	main(void)
{
	char temp[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

	printf("%s", ft_strcapitalize(temp));
}
