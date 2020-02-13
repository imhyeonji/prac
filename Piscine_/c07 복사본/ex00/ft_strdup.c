/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:33:09 by hyim              #+#    #+#             */
/*   Updated: 2020/02/05 20:24:23 by hyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *src)
{
	int i;
	
	i = 0;
	while(src[i] != '\0')
        i++;
	return (i + 1);
}

char	*ft_strcpy(char *dest, char *src)
{
	char *temp;

	temp = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	return (temp);
}

char	*ft_strdup(char *src) //function is used to duplicate a string.
{
	char *dest; 

	dest = (char*)malloc(sizeof(char) * ft_strlen(src));
	dest = ft_strcpy(dest, src);
	return (dest);
}
//returns pointer to a null-terminated byte string, which is a duplicate of the string pointed to by src

int	 main(int argc, char** argv) 
{
  printf("%s", ft_strdup(argv[1]));
  return 0;
}
