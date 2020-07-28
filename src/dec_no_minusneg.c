/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_no_minusneg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssacrist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 19:50:58 by ssacrist          #+#    #+#             */
/*   Updated: 2020/07/22 19:51:27 by ssacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	if_nominus_noneg_d(int arg, t_format *carrier)
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
	ft_putnbr(arg, carrier);
}
