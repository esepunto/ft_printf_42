/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jotdown_dec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssacrist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 16:25:34 by ssacrist          #+#    #+#             */
/*   Updated: 2020/07/23 17:10:14 by ssacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	jotdown_d(t_format *carrier)
{
	int		arg;

	flag(carrier->flagstr, 0, carrier);
	arg = va_arg(carrier->arguments, int);
	carrier->large_arg = ft_strlen(ft_itoa(arg));
	adjust_flags(carrier);
	print_d(arg, carrier);
}

void	print_d(int arg, t_format *carrier)
{
	if (carrier->precision == 0 && arg == 0)
		writespaces(carrier->width, carrier);
	else if (carrier->minus == 1)
		if_minus_d(arg, carrier);
	else if (arg < 0)
		if_neg_d(arg, carrier);
	else
		if_nominus_noneg_d(arg, carrier);
}
