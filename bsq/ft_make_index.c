/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:22:44 by kyang             #+#    #+#             */
/*   Updated: 2020/02/13 07:57:47 by hyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_globals.h"

int		ft_hol(void)
{
	g_error++;
	return (0);
}

int		ft_make_index(void)
{
	int i;
	int j;

	if ((g_index = (int**)malloc(sizeof(int*) * (g_row))) == NULL)
	{
		ft_hol();
	}
	i = 0;
	while (i < g_row)
	{
		if ((g_index[i] = (int*)malloc(sizeof(int) * (g_column))) == NULL)
		{
			g_error++;
			return (0);
		}
		j = 0;
		while (j < g_column)
		{
			g_index[i][j] = 1;
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int		ft_put_obstacles(int y, int x)
{
	while (y < g_row)
	{
		while (x < g_column)
		{
			if (g_map[y][x] == g_obst)
				g_index[y][x] = 0;
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
