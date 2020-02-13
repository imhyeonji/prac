/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 20:09:11 by hyim              #+#    #+#             */
/*   Updated: 2020/01/30 10:49:51 by hyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int n;

	n = 0;
	while(str[n] != '\0')
	{
		n++;
	}
	return (n);
}

int	main(void)
{
	char str[100] = "abcdf";

	printf("%d", ft_strlen(str));
	return (0);
}
