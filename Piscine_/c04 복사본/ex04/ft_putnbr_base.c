/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:11:26 by hyim              #+#    #+#             */
/*   Updated: 2020/01/31 10:13:40 by hyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_error(char *base)
{
	int i;
	int j;

	i = 0;
	j = i + 1;
	while(base[i] != '\0')
	{
		if(base[0] == '\0' || base[1] == '\0'
				|| base[i] == '-' || base[i] == '+'
				|| base[i] == base[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int i;
	char *temp;

	i = 0;
	temp = base;
	while (base[i] != '\0' && ft_error(base))
	{
		i++;
	}
	if (nbr == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr_base(147483648, temp);
	}
	else if (nbr >= i)
	{
		ft_putnbr_base(nbr / i, temp);
		ft_putchar(temp[(nbr % i)]);
	}
	else if (nbr < i && nbr >= 0)
		ft_putchar(temp[(nbr % i)]);
	else if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr_base((nbr * -1), temp);
	}
}

#include <limits.h>

int		main(void)
{
	ft_putnbr_base(-123456, "helo");
	printf("\n");
	fflush(stdout);
	ft_putnbr_base(INT_MIN, "0123456789");
	printf("\n");
	fflush(stdout);
	ft_putnbr_base(INT_MAX, "0123456789");
}
