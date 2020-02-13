/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_bsq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 00:03:49 by kyang             #+#    #+#             */
/*   Updated: 2020/02/13 04:33:08 by kyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_globals.h"

int		ft_find_minimum(int a, int b, int c)
{
	int min;

	min = a;
	if (b <= a && b <= c)
		min = b;
	else if (c <= a && c <= b)
		min = c;
	return (min + 1);
}

void	ft_check_square(int y, int x)
{
	if (g_index[y - 1][x - 1] != 0 &&
			g_index[y - 1][x] != 0 &&
			g_index[y][x - 1] != 0 &&
			g_index[y][x] != 0)
	{
		g_index[y][x] = ft_find_minimum(g_index[y - 1][x - 1],
				g_index[y - 1][x], g_index[y][x - 1]);
	}
}

int		ft_move_square(int y, int x)
{
	while (y < g_row)
	{
		while (x < g_column)
		{
			ft_check_square(y, x);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

int		ft_find_bsq(int y, int x)
{
	ft_move_square(1, 1);
	g_MAX = 0;
	while (y < g_row)
	{
		while (x < g_column)
		{
			if (g_index[y][x] > g_MAX)
			{
				g_MAX = g_index[y][x];
				g_max_x = x;
				g_max_y = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}
