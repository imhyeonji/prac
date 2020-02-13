/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 00:09:19 by hyim              #+#    #+#             */
/*   Updated: 2020/02/05 21:17:55 by hyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int len;
	int i;

	if (min >= max)
		return (0); 
	len = max - min;
	*range = (int *)malloc(sizeof(min) * len);
	i = 0;
	while (i < max)
	{
		*(range[0] + i) = min + i;
		i++;
	}
	return(len);
}

#include <stdio.h>
int   main(void)
{
  int* res = NULL;
  int i;
  int size;

  printf("%d", ft_ultimate_range(&res, 10, 30));
  return (0);
}
