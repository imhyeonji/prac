/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 05:09:14 by kyang             #+#    #+#             */
/*   Updated: 2020/02/13 07:40:27 by hyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_globals.h"

char	*ft_plusalloc(char *storage, char *buffer, int file_size, int i)
{
	char	*arr;
	int		j;

	if ((arr = (char*)malloc(sizeof(char) * (file_size + 1))) == NULL)
	{
		g_error++;
		return (0);
	}
	j = 0;
	while (storage[i])
	{
		arr[i] = storage[i];
		i++;
	}
	while (buffer[j])
	{
		arr[i + j] = buffer[j];
		j++;
	}
	free(storage);
	arr[i + j] = '\0';
	return (arr);
}

void	ft_copy_strings(char *storage)
{
	int i;

	i = 0;
	while (storage[i])
	{
		g_temp[i] = storage[i];
		i++;
	}
}

int		ft_sol(void)
{
	g_error++;
	return (1);
}

char	*ft_stdin_control(void)
{
	char	*buffer;
	char	*storage;
	int		file_size;
	int		temp;

	temp = 0;
	file_size = 0;
	if ((storage = (char*)malloc(sizeof(char) * 1024)) == NULL)
	{
		ft_sol();
	}
	if ((buffer = (char*)malloc(sizeof(char) * 1024)) == NULL)
	{
		ft_sol();
	}
	while ((temp = read(0, buffer, 1024) > 0))
	{
		file_size = file_size + temp;
		buffer[temp] = '\0';
		storage = ft_plusalloc(storage, buffer, file_size, 0);
	}
	free(buffer);
	g_temp = (char*)malloc(sizeof(char) * sizeof(storage));
	ft_copy_strings(storage);
	return (storage);
}
