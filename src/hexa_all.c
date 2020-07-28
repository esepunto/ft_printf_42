/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssacrist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 19:31:45 by ssacrist          #+#    #+#             */
/*   Updated: 2020/07/28 02:31:19 by ssacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void	if_minus_precision_x(char *arg, t_format *carrier)
{
	if (carrier->precision > carrier->large_arg)
	{
		writezeros(carrier->precision - carrier->large_arg, carrier);
		ft_puthex(arg, carrier);
		if (carrier->width > carrier->precision)
			writespaces(carrier->width - carrier->precision, carrier);
	}
	else
		aux_print_spaces_x(arg, carrier);
}

static void	if_minus_noprecision_x(char *arg, t_format *carrier)
{
	if (carrier->width > 0)
	{
		if (carrier->width >= carrier->large_arg)
			aux_print_spaces_x(arg, carrier);
		else
			ft_puthex(arg, carrier);
	}
	else
		ft_puthex(arg, carrier);
}

void		if_minus_x(char *arg, t_format *carrier)
{
	if (carrier->precision >= 0)
		if_minus_precision_x(arg, carrier);
	else
		if_minus_noprecision_x(arg, carrier);
}

void		if_nominus_noneg_x(char *arg, t_format *carrier)
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
	ft_puthex(arg, carrier);
}
