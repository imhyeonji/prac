/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:49:48 by hyim              #+#    #+#             */
/*   Updated: 2020/01/28 10:03:21 by hyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i <= n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int main()
{
 char dest[] = "asdfasdfasdf";

 printf("%s\n", ft_strncpy(dest, "qwerty", 4));
 printf("%s\n", ft_strncpy(dest, "z", 1));
 printf("%s", ft_strncpy(dest, "zz", 5));

 return(0);
}
