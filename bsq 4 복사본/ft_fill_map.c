/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 01:55:43 by kyang             #+#    #+#             */
/*   Updated: 2020/02/13 04:33:10 by kyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_globals.h"

int	ft_fill_map(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < g_MAX)
	{
		while (i < g_MAX)
		{
			g_map[g_max_y - j][g_max_x - i] = g_fill;
			i++;
		}
		j++;
		i = 0;
	}
	return (1);
}

int	ft_print_map(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < g_row)
	{
		while (j < g_column)
		{
			write(1, &g_map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
	return (1);
}

int	ft_reset_all(int j)
{
	while (j < g_row)
	{
		free(g_map[j]);
		free(g_index[j]);
		j++;
	}
	free(g_map);
	free(g_index);
	free(g_temp);
	g_empty = 0;
	g_obst = 0;
	g_fill = 0;
	g_front = 0;
	g_row = 0;
	g_column = 0;
	return (1);
}
