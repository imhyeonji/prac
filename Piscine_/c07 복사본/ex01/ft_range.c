/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 13:29:45 by hyim              #+#    #+#             */
/*   Updated: 2020/02/05 21:14:40 by hyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

//배열을 반환하는 함수. min <= int배열 < max사이의 모든 값을 포함
//min이max보다 크거나 같으면 null이 반환되어야함
int *ft_range(int min, int max)
{
	int *num;
	int len;
	int j;

	if (min >= max)
		return (0);
	len = max - min;
	num = (int*)malloc(sizeof(min) * (len));
	j = 0;
	while (j < max)
	{
		num[j] = min;
		j++;
		min++;
	}		
	return (num);
}

int	main(void)
{
	int *a;
	int i;
	int size;
	
	a = ft_range(333, 521);
	i = 0;
	size = 4 - 2;
	while (i < (521-333))
	{
		printf("%d" ",", a[i]);
		i++;
	}
}
