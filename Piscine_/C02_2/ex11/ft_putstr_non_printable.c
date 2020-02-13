/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:02:42 by hyim              #+#    #+#             */
/*   Updated: 2020/01/28 18:03:09 by hyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	ft_print_hex(unsigned char c)	//unsigned char
{
	int remain;

	remain = c % 16;
	if (remain < 10)
	{
		ft_putchar('\\');
		ft_putchar('0' + c / 16);
		ft_putchar('0' + remain);
	}
	else
	{
		ft_putchar('\\');
		ft_putchar('0' + c / 16);
		ft_putchar('a' + (remain - 10));
	}
	return 0;
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 32 && str[i] <= 126))
		{
			ft_print_hex(str[i]);
		}
		else 
		{
			ft_putchar(str[i]);
		}
		i++;
	}
}

int	main()
{
	ft_putstr_non_printable("Coucou\ntu vas bien ?");
	return 0;
}
