/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:59:51 by kyang             #+#    #+#             */
/*   Updated: 2020/02/13 08:03:41 by hyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_globals.h"

int		ft_make_temp(char *av, int size, int i, int j)
{
	int fd;

	if ((g_temp = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
	{
		g_error++;
		return (0);
	}
	fd = open(av, O_RDONLY);
	read(fd, g_temp, size);
	g_temp[size] = '\0';
	while (g_temp[i] != '\n')
		i++;
	g_fill = g_temp[i - 1];
	g_obst = g_temp[i - 2];
	g_empty = g_temp[i - 3];
	if ((i = i - 4) < 0)
	{
		g_error++;
		return (0);
	}
	while (++j <= i)
		g_front = (g_front * 10) + (g_temp[j] - '0');
	close(fd);
	return (1);
}

int		ft_count_col_and_row(int i, int temp_row)
{
	while (g_temp[i] != '\n')
		i++;
	i++;
	while (g_temp[i] != '\n')
	{
		i++;
		g_column++;
	}
	i++;
	while (g_temp[i])
	{
		temp_row = 0;
		while (g_temp[i] != '\n')
		{
			i++;
			temp_row++;
		}
		if (g_column - temp_row != 0)
			ft_hol();
		g_row++;
		i++;
	}
	g_row++;
	return (1);
}

int		ft_malloc_map(void)
{
	int i;

	i = 0;
	if ((g_map = (char**)malloc(sizeof(char*) * (g_row + 1))) == NULL)
	{
		g_error++;
		return (0);
	}
	while (i < g_row)
	{
		if ((g_map[i] = (char*)malloc(sizeof(char) * (g_column + 1))) == NULL)
		{
			ft_hol();
		}
		i++;
	}
	return (1);
}

void	ft_split(int i, int j, int k)
{
	while (g_temp[i] != '\n')
		i++;
	while (g_temp[i])
	{
		while (g_temp[i] != '\n')
		{
			g_map[j][k] = g_temp[i];
			i++;
			k++;
		}
		if (k == g_column)
		{
			g_map[j][k] = '\0';
			k = 0;
			j++;
		}
		i++;
	}
	g_map[j] = "\0";
}

int		ft_read_file(char *av)
{
	int		fd;
	int		size;
	int		temp;
	char	buf[1024];

	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		g_error++;
		return (0);
	}
	size = 0;
	while ((temp = read(fd, &buf, sizeof(buf))) > 0)
		size = size + temp;
	close(fd);
	if (ft_make_temp(av, size, 0, -1) == 0
			|| ft_count_col_and_row(0, 0) == 0 || ft_malloc_map() == 0)
	{
		g_error++;
		return (0);
	}
	ft_split(0, 0, 0);
	return (1);
}
