/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssacrist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 18:06:22 by ssacrist          #+#    #+#             */
/*   Updated: 2020/07/23 18:06:43 by ssacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftprintf.h"

void	writespaces(int c, t_format *carrier)
{
	while (c-- > 0)
		ft_putchar(' ', carrier);
}

void	aux_print_spaces(int arg, t_format *carrier)
{
	ft_putnbr(arg, carrier);
	writespaces(carrier->width - carrier->large_arg, carrier);
}

void	aux_print_spaces_u(unsigned int arg, t_format *carrier)
{
	ft_putnbr_u(arg, carrier);
	writespaces(carrier->width - carrier->large_arg, carrier);
}

void	aux_print_spaces_x(char *arg, t_format *carrier)
{
	ft_puthex(arg, carrier);
	writespaces(carrier->width - carrier->large_arg, carrier);
}

void	writespaces_s(t_format *carrier)
{
	int c;

	if (carrier->arg_null == 'y' && carrier->width > carrier->large_arg
						&& carrier->dot == 0)
		c = carrier->width - carrier->large_arg;
	else if (carrier->precision >= 0 && carrier->dot == 1
						&& carrier->precision < carrier->large_arg)
		c = carrier->width - carrier->precision;
	else if (carrier->arg_null == 'y' && carrier->large_arg > carrier->width
						&& carrier->dot == 0)
		c = 0;
	else
		c = carrier->width - carrier->large_arg;
	while (c-- > 0)
		ft_putchar(' ', carrier);
}
