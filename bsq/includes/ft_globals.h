/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_globals.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 01:04:27 by kyang             #+#    #+#             */
/*   Updated: 2020/02/13 07:59:06 by hyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GLOBALS_H
# define FT_GLOBALS_H

int		g_error;
char	**g_map;
char	*g_temp;
char	g_empty;
char	g_fill;
char	g_obst;
int		g_front;
int		g_column;
int		g_row;
int		**g_index;
int		g_big;
int		g_max_x;
int		g_max_y;

int		ft_read_file(char *av);
int		ft_make_index(void);
int		ft_put_obstacles(int y, int x);
int		ft_check_char(int y, int x);
int		ft_find_bsq(int y, int x);
int		ft_fill_map(void);
int		ft_print_map(void);
int		ft_reset_all(int j);
char	*ft_stdin_control(void);
int		ft_count_col_and_row(int i, int temp_row);
int		ft_malloc_map(void);
void	ft_split(int i, int j, int k);
int		ft_sol(void);
int		ft_hol(void);

#endif
