/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:56:54 by kyang             #+#    #+#             */
/*   Updated: 2020/02/13 04:27:39 by kyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_globals.h"

int	ft_solution_wizard(void)
{
	ft_check_char(0, 0);
//	if (g_row != g_front)
//	{
//		printf("g_row = %d, front = %d\n", g_row, g_front);
//		g_error++;
//		return (0);
//	}
	ft_make_index();
	ft_put_obstacles(0, 0);
	ft_find_bsq(0, 0);
	ft_fill_map();
	return (1);
}

int	main(int argc, char **argv)
{
	int map_no;

	map_no = 1;
	if (argc == 1);
//	 	ft_stdin_control();
	else
	{
		while (map_no < argc)
		{
			g_error = 0;
			if (ft_read_file(argv[map_no]) != 0)
				ft_solution_wizard();
			if (g_error > 0)
				write(2, "map error\n", 10);
			else
			{
				ft_print_map();
				ft_reset_all(0);
			}
			if (map_no < argc - 1)
				write(1, "\n", 1);
			map_no++;
		}
	}
}
