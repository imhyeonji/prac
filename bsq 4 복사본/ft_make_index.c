/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:22:44 by kyang             #+#    #+#             */
/*   Updated: 2020/02/13 04:33:04 by kyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_globals.h"

#include <stdio.h> /*******************************************/

/*
** g_map과 동일한 사이즈의 2차원 배열 정수 어레이를 만들어줌.
** 이 어레이를 통해 최대 사이즈의 정사각형 찾아냄.
*/

int		ft_make_index(void)
{
	int i;
	int j;

	if ((g_index = (int**)malloc(sizeof(int*) * (g_row))) == NULL)
		{
			g_error++;
			return (0);
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

/*
** g_map을 읽어서 g_index의 장애물 자리를 
** 0으로 교체해줌!
*/

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
