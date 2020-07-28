/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_to_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssacrist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 18:02:53 by ssacrist          #+#    #+#             */
/*   Updated: 2020/07/28 01:50:31 by ssacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftprintf.h"

void	ft_putchar(int c, t_format *carrier)
{
	write(1, &c, 1);
	carrier->how_many++;
}

void	ft_putnbr(int nb, t_format *carrier)
{
	unsigned int	copy_nb;

	if (nb < 0)
	{
		ft_putchar('-', carrier);
		nb = (nb * (-1));
	}
	copy_nb = nb;
	if (copy_nb > 9)
		ft_putnbr(copy_nb / 10, carrier);
	ft_putchar(copy_nb % 10 + '0', carrier);
}

void	ft_putnbr_u(unsigned int nb, t_format *carrier)
{
	unsigned int	copy_nb;

	copy_nb = nb;
	if (nb > 9)
		ft_putnbr_u(copy_nb / 10, carrier);
	ft_putchar(copy_nb % 10 + '0', carrier);
}

void	ft_putstr(char *str, t_format *carrier)
{
	int		c;

	c = carrier->precision;
	if (!str)
		return ;
	if (c > 0)
	{
		while (*str && c-- > 0)
		{
			ft_putchar(*str, carrier);
			str++;
		}
	}
	else if (carrier->precision < 0)
	{
		while (*str)
		{
			ft_putchar(*str, carrier);
			str++;
		}
	}
}

void	ft_puthex(char *str, t_format *carrier)
{
	if (!str)
		return ;
	while (*str)
	{
		ft_putchar(*str, carrier);
		str++;
	}
}
