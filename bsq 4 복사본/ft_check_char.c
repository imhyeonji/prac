/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:46:46 by kyang             #+#    #+#             */
/*   Updated: 2020/02/13 04:34:03 by kyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_globals.h"

/*
** fill, obst, empty가 출력가능한 문자인지 확인
*/

int		ft_check_printable(void)
{
	if (g_empty < 32 || g_empty > 126 ||
			g_fill < 32 || g_fill > 126 ||
			g_obst < 32 || g_obst > 126)
		return (0);
	return (1);
}

/*
** fill, obst, empty캐릭터 중 중복되는 것이
** 있는지를 검사
*/

int		ft_check_char(int y, int x)
{
	if (g_fill == g_obst || g_obst == g_empty
			|| g_empty == g_fill
			|| ft_check_printable() == 0)
	{
		g_error++;
		return (0);
	}
	while (y < g_row)
	{
		while (x < g_column)
		{
			if (g_map[y][x] != g_empty && g_map[y][x] != g_obst)
			{
				g_error++;
				return (0);	
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}
