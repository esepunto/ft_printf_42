/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_neg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssacrist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:20:26 by ssacrist          #+#    #+#             */
/*   Updated: 2020/07/28 02:29:25 by ssacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void	if_neg_precision_d(int arg, t_format *carrier)
{
	if (carrier->precision < carrier->large_arg)
		writespaces(carrier->width - carrier->large_arg, carrier);
	else if (carrier->width > carrier->precision)
		writespaces((carrier->width - carrier->precision) - 1, carrier);
	if (arg < 0)
	{
		arg = arg * (-1);
		ft_putchar('-', carrier);
	}
	writezeros(carrier->precision - carrier->large_arg + 1, carrier);
	print_int_min_pos(arg, carrier);
}

static void	if_neg_noprecision_d(int arg, t_format *carrier)
{
	if (carrier->zero == 1)
	{
		if (arg < 0)
		{
			arg = arg * (-1);
			ft_putchar('-', carrier);
		}
		writezeros(carrier->width - carrier->large_arg, carrier);
		print_int_min_pos(arg, carrier);
	}
	else
	{
		writespaces(carrier->width - carrier->large_arg, carrier);
		print_int_min_neg(arg, carrier);
	}
}

void		if_neg_d(int arg, t_format *carrier)
{
	if (carrier->precision >= 0)
		if_neg_precision_d(arg, carrier);
	else
		if_neg_noprecision_d(arg, carrier);
}
