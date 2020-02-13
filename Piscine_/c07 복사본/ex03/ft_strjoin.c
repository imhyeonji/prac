/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 00:58:02 by hyim              #+#    #+#             */
/*   Updated: 2020/02/06 12:22:53 by hyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	char *temp;

	temp = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (temp);
}

char	*ft_strcpy(char *dest, char *src)
{
	char *temp;

	temp = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (temp);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char *temp;
	int strs_len;
	int sep_len;
	int i;

	i = -1;
	strs_len = 0;
	while (++i < size)
		strs_len = strs_len + ft_strlen(strs[i]);
	sep_len = ft_strlen(sep);
	printf("strs_len : %d / sep_len = %d \n", strs_len, sep_len);
	if (size <= 0)
	{
		temp = malloc(sizeof(char));
		*temp = 0;
		return (temp);
	}
	temp = malloc(sizeof(char) * (strs_len + (sep_len * (size - 1)) + 1));
	*temp = 0;
	i = -1;
	while (++i < size)
	{
		temp = ft_strcat(temp, strs[i]);
		//printf("test: %s\n", temp);
		if (i == size -1)
			break;
		temp = ft_strcat(temp, sep);
	}
	//printf("1st : %s\n", temp);
	//printf("strlen?? %d\n", strs_len);
	temp[strs_len + sep_len * (size - 1)] = '\0';
	//printf("2nd : %s\n", temp);
	return (temp);
}

int	main(void)
{
	char *strs[55] = {"aaa", "bbb", "kkk", "wow", "try", "soooosad"};
	char sep[10] = ", ";
	//char stupid[10] = "why";
	int size = 6;
	//char temp[80] = "stupid";

	printf("final: %s\n", ft_strjoin(size, strs, sep));
	//printf("%s", ft_strcat(stupid, sep));
}	
