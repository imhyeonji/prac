/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 12:31:27 by hyim              #+#    #+#             */
/*   Updated: 2020/01/30 16:56:41 by hyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_countm(char *str)
{
	int n;

	n = 0;
	while (*str)
	{
		if (*str == '-')
			n++;
		str++;
	}
	if (n % 2 == 1)
		return (-1);
	else 
		return (1);
}

int	ft_atoi(char *str)
{
	int n;
	char *temp;

	temp = str;
	n = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\f' || *str == '\r'))
	{
		str++;
	}
	while (*str == '-' || *str == '+')
	{
		str++;
	}
	while(*str && *str >= '0' && *str <='9')
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	return (n * ft_countm(temp));
}

int	main(void)
{
	char str[] = "  ---+--+178512dsdfsdfb567";

	printf("%d", ft_atoi(str));
	return (0);
}
