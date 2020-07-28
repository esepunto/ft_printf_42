/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsign_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssacrist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 19:41:24 by ssacrist          #+#    #+#             */
/*   Updated: 2020/07/28 01:43:12 by ssacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void	if_minus_precision_u(unsigned int arg, t_format *carrier)
{
	if (carrier->precision > carrier->large_arg)
	{
		writezeros(carrier->precision - carrier->large_arg, carrier);
		ft_putnbr_u(arg, carrier);
		if (carrier->width > carrier->precision)
			writespaces(carrier->width - carrier->precision, carrier);
	}
	else
		aux_print_spaces_u(arg, carrier);
}

static void	if_minus_noprecision_u(unsigned int arg, t_format *carrier)
{
	if (carrier->width > 0)
	{
		if (carrier->width >= carrier->large_arg)
			aux_print_spaces_u(arg, carrier);
		else
			ft_putnbr_u(arg, carrier);
	}
	else
		ft_putnbr_u(arg, carrier);
}

void		if_minus_u(unsigned int arg, t_format *carrier)
{
	if (carrier->precision >= 0)
		if_minus_precision_u(arg, carrier);
	else
		if_minus_noprecision_u(arg, carrier);
}

void		if_nominus_noneg_u(unsigned int arg, t_format *carrier)
{
	if (carrier->precision >= 0)
	{
		if (carrier->precision <= carrier->large_arg)
			writespaces(carrier->width - carrier->large_arg, carrier);
		else if (carrier->width > carrier->precision)
			writespaces(carrier->width - carrier->precision, carrier);
		writezeros(carrier->precision - carrier->large_arg, carrier);
	}
	else if (carrier->zero == 1)
		writezeros(carrier->width - carrier->large_arg, carrier);
	else
		writespaces(carrier->width - carrier->large_arg, carrier);
	ft_putnbr_u(arg, carrier);
}
