/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 21:01:59 by hyim              #+#    #+#             */
/*   Updated: 2020/01/28 13:37:53 by hyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (src[i] != 0 && src[i] < src[size-1])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	printf("%s\n", dest);
	return (i);
}

int	main()
{
	char dest[] = "asdfasdfasdf";

 	printf("%d\n", ft_strlcpy(dest, "hello", 3));
 	printf("%d\n", ft_strlcpy(dest, "zsz", 2));
 	printf("%d", ft_strlcpy(dest, "zz", 5));

 	return(0);
}
