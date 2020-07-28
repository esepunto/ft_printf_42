/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_left_minus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssacrist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:16:03 by ssacrist          #+#    #+#             */
/*   Updated: 2020/07/28 02:28:44 by ssacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void	if_minus_neg_d(int arg, t_format *carrier)
{
	if (carrier->precision >= 0)
	{
		if (carrier->precision < carrier->large_arg)
			aux_print_spaces(arg, carrier);
		else
		{
			if (arg < 0)
			{
				arg = arg * (-1);
				ft_putchar('-', carrier);
			}
			writezeros(carrier->precision - carrier->large_arg + 1, carrier);
			print_int_min_pos(arg, carrier);
			if (carrier->width > carrier->precision)
				writespaces(carrier->width - carrier->precision - 1, carrier);
		}
	}
	else if (carrier->zero == 0)
		aux_print_spaces(arg, carrier);
}

static void	if_minus_precision_d(int arg, t_format *carrier)
{
	if (carrier->precision > carrier->large_arg)
	{
		writezeros(carrier->precision - carrier->large_arg, carrier);
		ft_putnbr(arg, carrier);
		if (carrier->width > carrier->precision)
			writespaces(carrier->width - carrier->precision, carrier);
	}
	else
		aux_print_spaces(arg, carrier);
}

static void	if_minus_noprecision_d(int arg, t_format *carrier)
{
	if (carrier->width > 0)
	{
		if (carrier->width >= carrier->large_arg)
			aux_print_spaces(arg, carrier);
		else
			ft_putnbr(arg, carrier);
	}
	else
		ft_putnbr(arg, carrier);
}

void		if_minus_d(int arg, t_format *carrier)
{
	if (arg < 0)
		if_minus_neg_d(arg, carrier);
	else if (carrier->precision >= 0)
		if_minus_precision_d(arg, carrier);
	else
		if_minus_noprecision_d(arg, carrier);
}
